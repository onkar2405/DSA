#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<int> adj[], int source, int size)
{
  vector<bool> visited(size, false);
  queue<int> q;
  q.push(source);
  visited[source] = true;

  vector<int> arr;

  while (!q.empty())
  {
    int num = q.front(); // 0
    q.pop();
    arr.push_back(num);

    for (int i : adj[num])
    {
      if (!visited[i])
      {
        visited[i] = true;
        q.push(i);
      }
    }
  }

  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
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