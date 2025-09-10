#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
  adj[u].push_back(v);
  adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int v)
{
  for (int i = 0; i < v; i++)
  {
    for (int j = 0; j < adj[i].size(); j++)
    {
      cout << adj[i][j] << " ";
    }
    cout << "\n";
  }
}

int main()
{
  int v = 5;
  vector<int> adj[v];

  addEdge(adj, 0, 1);
  addEdge(adj, 0, 2);
  addEdge(adj, 2, 3);
  addEdge(adj, 2, 4);
  printGraph(adj, v);

  return 0;
}