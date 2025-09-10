#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void BFS(vector<int> adj[], int source, int size)
{
  unordered_map<int, int> umap;

  for (int i = source; i < size; i++)
  {
    if (umap.find(i) == umap.end())
    {
      cout << i << " ";
      umap[i] = 1;
    }
    for (int j = 0; j < adj[i].size(); j++)
    {
      if (umap.find(adj[i][j]) == umap.end())
      {
        cout << adj[i][j] << " ";
        umap[adj[i][j]] = 1;
      }
    }
  }
}

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
  int source = 0;
  vector<int> adj[v];

  addEdge(adj, 0, 1);
  addEdge(adj, 0, 2);
  // addEdge(adj, 0, 5);
  addEdge(adj, 1, 3);
  addEdge(adj, 2, 4);
  addEdge(adj, 3, 4);
  // addEdge(adj, 4, 5) ;

  // printGraph(adj, v);
  BFS(adj, source, v);
  return 0;
}