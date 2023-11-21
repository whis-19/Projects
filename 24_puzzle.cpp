#include<iostream>
#include<conio.h>
#include<iomanip>
#include<cstdlib>
#include<time.h>
#include<windows.h>
#include"functions.h"
#include<iostream>
#include<conio.h>
#include<iomanip>
#include<cstdlib>
#include<time.h>
#include<windows.h>
#include<fstream>

using namespace std;

int color_ch;
int initial[5][5] = { 0 };
int goal_state[5][5] = { 0 };
char move_1;
char game[9999];
int state[5][5];


void color(int color_ch)
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, color_ch);
}

void init()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			initial[i][j] = 0;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j += 2)
		{
			initial[i][j] = (rand() % 25) + 1;
			int col = j;
			for (int k = 0; k < 5; k++)
			{
				for (int l = 0; l < 5; l++)
				{
					if (initial[i][col] == initial[k][l])
					{
						j--;
					}
				}
			}
		}
	}
}

void init_record(int initial[5][5])
{
	ofstream init;
	init.open("initial.txt");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			init << initial[i][j] << " ";
		}
		init << endl;
	}
	init.close();
}

void goal_record(int goal_state[5][5])

{
	ofstream goal;
	goal.open("goal.txt");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			goal << goal_state[i][j] << " ";
		}
		goal << endl;
	}
	goal.close();
}

void goal()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j += 2)
		{
			goal_state[i][j] = (rand() % 25) + 1;
			int col = j;
			for (int k = 0; k < 5; k++)
			{
				for (int l = 0; l < 5; l++)
				{
					if (goal_state[i][col] == goal_state[k][l])
					{
						j--;
					}
				}
			}
		}
	}
}

int invcount(int a[5][5])
{
	int inv[25];
	int count = 0;
	for (int i = 0, k = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++, k++)
		{
			inv[k] = a[i][j];
		}
	}
	for (int i = 0; i < 25; i++)
	{
		for (int j = i; j < 25; j++)
		{
			if (inv[i] > inv[j] && inv[i] != 25)
			{
				count++;
			}
		}
	}
	return count;
}

bool issolvable(int a, int b)
{
	if (a % 2 == b % 2)
	{
		return true;
	}
	else
		return false;
}

bool is_goal(int state[5][5], int goal_state[5][5])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (state[i][j] == goal_state[i][j])
			{
				continue;
			}
			else
			{
				return false;
			}
		}
	}
	return true;
}

void make_move(int init_state[5][5], char move)
{
	int row, col, temp = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (init_state[i][j] == 25)
			{
				row = i;
				col = j;
				break;
			}
		}
	}
	int i = row;
	int j = col;
	switch (move)
	{
	case 's':
	case 'S':
		if (i != 4)
		{
			temp = init_state[i][j];
			init_state[i][j] = init_state[i + 1][j];
			init_state[i + 1][j] = temp;
		}
		break;
	case 'd':
	case 'D':
		if (j != 4)
		{
			temp = init_state[i][j];
			init_state[i][j] = init_state[i][j + 1];
			init_state[i][j + 1] = temp;
		}
		break;
	case 'W':
	case 'w':
		if (i != 0)
		{
			temp = init_state[i][j];
			init_state[i][j] = init_state[i - 1][j];
			init_state[i - 1][j] = temp;
		}
		break;
	case 'A':
	case 'a':
		if (j != 0)
		{
			temp = init_state[i][j];
			init_state[i][j] = init_state[i][j - 1];
			init_state[i][j - 1] = temp;
		}
		break;
	}
}

int legal_moves(int init_state[5][5])
{
	for (int i = 0; i <= 4; i++)
	{
		for (int j = 0; j <= 4; j++)
		{
			if (init_state[i][j] == 25)
			{
				if (i == 4)
				{
					color(7);
					cout << "You cannot move downward. " << endl;
				}
				if (i == 0)
				{
					color(7);
					cout << "You cannot move upwards. " << endl;
				}
				if (j == 0)
				{
					color(7);
					cout << "You cannot move leftward. " << endl;
				}
				if (j == 4)
				{
					color(7);
					cout << "You cannot move rightward. " << endl;
				}
			}
		}
	}
	return 0;
}

void disp(int a[][5])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (a[i][j] == 25)
			{
				cout << setw(5) << "-";
			}
			else
			{
				cout << setw(5) << a[i][j];
			}
		}
		cout << endl;
	}
}

void print_path()
{
	ofstream moves("move_record.txt");
	color(7);
	moves << "The moves you entered are: ";
	int counter = 0;
	int c = 0;
	color(7);
	cout << "The moves you eneterd are as follows : " << endl;
	for (int i = 0; game[i] != '\0'; i++)
	{
		if (game[i] != '#')
		{
			color(6);
			cout << game[i] << "\t";
			moves << game[i] << ",  " << "\t";
			c++;
			if (c == 10)
			{
				cout << endl;
				c = 0;
			}
			counter++;
		}
		else
		{
			break;
		}
	}
	moves << endl;
	cout << endl;
	color(7);
	cout << "Total no.of moves are : " << counter;
}





int main()
{
	int cal = 0;
	srand(time(0));
	color(1);
	cout << "Initial state : " << endl;
	color(1);
	init();
	goal();
	do
	{
		init();
		color(7);
	} while (!issolvable(invcount(initial), invcount(goal_state)));
	disp(initial);
	do
	{
		color(7);
		cout << "\t\t\t\t\t------------" << endl;
		cout << "\t\t\t\t\tIntructions " << endl;
		cout << "\t\t\t\t\t------------" << endl;
		cout << "1.\tUse w/W to move upward." << endl;
		cout << "2.\tUse s/S to move downward." << endl;
		cout << "3.\tUse a/A to move leftward." << endl;
		cout << "4.\tUse d/D to move rightward." << endl;
		cout << "5.\tEnter # to terminate game, you loser !!" << endl;
		color(4);
		cout << endl << "\t\t\t\t<<\tFor those who dare (-_-)\t>>" << endl;
		color(7);
		cout << "Goal state:\n";
		color(2);
		disp(goal_state);
		color(7);
		cout << "Game state:\n";
		color(2);
		disp(initial);
		color(6);
		legal_moves(initial);
		move_1 = _getch();
		if (move_1 == 'W' || move_1 == 'w' || move_1 == 'A' || move_1 == 'a' || move_1 == 'S' || move_1 == 's' || move_1 == 'D' || move_1 == 'd')
		{
			game[cal] = move_1;
			cal++;
		}
		make_move(initial, move_1);
		system("CLS");
	} while (!(is_goal(initial, goal_state) || move_1 == '#'));
	init_record(initial);
	goal_record(goal_state);
	if ((is_goal(initial,goal_state)))
	{
		color(7);
		cout << "You won the game. " << endl;
		color(6);
		print_path();
		cout<<endl;
		color(7);
		cout << "\t\t\t\t\tCredits" << endl;
		cout << endl<<"Game credits to Muhammad Omair and Muhammad Abdullah." << endl;
		cout << "First tester of this game is Muhammad Asjad." << endl;
		cout << "Final Project of PF." << endl;
		cout << "Submitted to Sir Tahir Farooq (Course intructor) and Sir Usman Azhar (LAB Instructor)." << endl;
		cout << "Submitted on 08/12/2022.";
	}
	else
	{
		color(7);
		cout << "You lost the game. " << endl;
		color(6);
		print_path();
		cout << endl;
		color(7);
		cout << "\t\t\t\t\tCredits" << endl;
		cout << endl << "Game credits to Muhammad Omair and Muhammad Abdullah." << endl;
		cout << "First tester of this game is Muhammad Asjad." << endl;
		cout << "Final Project of PF." << endl;
		cout << "Submitted to Sir Tahir Farooq (Course intructor) and Sir Usman Azhar (LAB Instructor)." << endl;
		cout << "Submitted on 07/12/2022.";
	}
}