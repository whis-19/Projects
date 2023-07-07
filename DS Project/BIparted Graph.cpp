#include <iostream>
#include <vector>
using namespace std;
//to check adjency
vector<vector<int>>adj;
//to check where the node is visted or not
vector<bool>visited;
//to check color
vector<int>col;
bool biparted;
void color(int crntnode, int clr)
{
	if (col[crntnode] != -1 && col[crntnode] != clr)
	{
		biparted = false;
		return;
	}
	col[crntnode] = clr;
	if (visited[crntnode])
	{
		return;
	}
	visited[crntnode] = true;
	for (auto i : adj[crntnode])
	{
		color(i, clr xor 1); // xor changes value from 0 to 1 and vice versa
	}

}
int main()
{
	biparted = true;
	int vertices, edges;
	cout << "Enter number of vertices : ";
	cin >> vertices;
	cout << "Enter number of edges : ";
	cin >> edges;
	adj = vector<vector<int>>(vertices);
	visited = vector<bool>(vertices, false);
	col = vector<int>(vertices, -1);
	cout << "Enter edges : \n";
	for (int i = 0; i < edges; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	// to check grapht is traverse
	for (int i = 0; i < vertices; i++)
	{
		if (!visited[i])
		{
			color(i, 0);
		}
	}
	if (biparted)
	{
		cout << "Graph is biparted";
	}
	else
	{
		cout << "Graph is not biparted";
	}

}