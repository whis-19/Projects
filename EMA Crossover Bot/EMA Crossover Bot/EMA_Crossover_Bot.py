
import MetaTrader5 as mt5
import plotly.express as px
import pandas as pd
import numpy as np
import talib

# Connect to MetaTrader 5
mt5.initialize()

# Settings
symbol = "EURUSD"
timeframe = mt5.TIMEFRAME_D1
start_pos = 0
num_bars = 1000

fsma_period = 10
ssma_period = 100

# Request historical data
bars = mt5.copy_rates_from_pos(symbol, timeframe, start_pos, num_bars)
df = pd.DataFrame(bars)[["time", "open", "high", "low", "close"]]
df['time'] = pd.to_datetime(df["time"], unit="s")

# Calculate moving averages using TA-Lib
df["fast_sma"] = talib.SMA(df["close"], timeperiod=fsma_period)
df["slow_sma"] = talib.SMA(df["close"], timeperiod=ssma_period)

# Finding crossovers
df["prev_fast_sma"] = df["fast_sma"].shift(1)
df.dropna(inplace=True)


def find_crossover(fast_sma, prev_fast_sma, slow_sma):
    if fast_sma > slow_sma and prev_fast_sma < slow_sma:
        return 'Bullish Crossover'
    elif fast_sma < slow_sma and prev_fast_sma > slow_sma:
        return 'Bearish Crossover'
    return None


df["Crossover"] = np.vectorize(find_crossover)(df["fast_sma"], df["prev_fast_sma"], df["slow_sma"])
signal = df[df["Crossover"] == "Bullish Crossover"].copy()
print(signal)


class Position:
    def __init__(self, open_datetime, open_price, order_type, volume, sl, tp):
        self.open_datetime = open_datetime
        self.open_price = open_price
        self.order_type = order_type
        self.volume = volume
        self.sl = sl
        self.tp = tp
        self.close_datetime = None
        self.close_price = None
        self.profit = None
        self.status = 'open'

    def close_position(self, close_datetime, close_price):
        self.close_datetime = close_datetime
        self.close_price = close_price
        self.profit = (self.close_price - self.open_price) * self.volume if self.order_type == 'buy' \
            else (self.open_price - self.close_price) * self.volume
        self.status = 'closed'

    def _asdict(self):
        return {
            'open_datetime': self.open_datetime,
            'open_price': self.open_price,
            'order_type': self.order_type,
            'volume': self.volume,
            'sl': self.sl,
            'tp': self.tp,
            'close_datetime': self.close_datetime,
            'close_price': self.close_price,
            'profit': self.profit,
            'status': self.status,
        }


class Strategy:
    def __init__(self, df, starting_balance, volume):
        self.starting_balance = starting_balance
        self.volume = volume
        self.positions = []
        self.data = df

    def get_positions_df(self):
        df = pd.DataFrame([position._asdict() for position in self.positions])
        df['pnl'] = df['profit'].cumsum() + self.starting_balance
        return df

    def add_position(self, position):
        self.positions.append(position)
        return True

    # logic
    def run(self):
        for i, data in self.data.iterrows():
            if data.Crossover == 'Bearish Crossover':
                for position in self.positions:
                    if position.status == 'open':
                        position.close_position(data.time, data.close)

            if data.Crossover == 'Bullish Crossover':
                self.add_position(Position(data.time, data.close, 'buy', self.volume, 0, 0))

        return self.get_positions_df()


sma_crossover_strategy = Strategy(df, 10000, 1)
result = sma_crossover_strategy.run()

print(result)

# Visualize PnL
fig_2 = px.line(result, x='close_datetime', y='pnl')
fig_2.show()

# Visualize close price and crossovers
fig = px.line(df, x='time', y=['close', 'fast_sma', 'slow_sma'])

for i, row in signal.iterrows():
    fig.add_vline(x=row.time)

for i, row in result[result['status'] == 'closed'].iterrows():
    if row.profit > 0:
        fig.add_shape(
            type="line",
            x0=row.open_datetime, y0=row.open_price, x1=row.close_datetime, y1=row.close_price,
            line=dict(color="green", width=3)
        )
    elif row.profit < 0:
        fig.add_shape(
            type="line",
            x0=row.open_datetime, y0=row.open_price, x1=row.close_datetime, y1=row.close_price,
            line=dict(color="red", width=3)
        )

fig.show()

