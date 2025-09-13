#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>> &adj, vector<int> &result, int size, vector<bool> &visited, int source)
{
  visited[source] = true;
  queue<int> q;
  q.push(source);

  while (!q.empty())
  {
    int num = q.front();
    q.pop();
    result.push_back(num);

    for (int i : adj[num])
    {
      if (!visited[i])
      {
        q.push(i);
        visited[i] = true;
      }
    }
  }
}

vector<int> bfsDisconnected(vector<vector<int>> &adj, int size)
{
  vector<int> result;
  vector<bool> visited(size, false);

  for (int i = 0; i < adj.size(); i++)
  {
    if (!visited[i])
    {
      bfs(adj, result, size, visited, i);
    }
  }

  return result;
}

int main()
{
  vector<vector<int>> adj = {{1, 2}, {0}, {0}, {4}, {3, 5}, {4}};
  vector<int> result = bfsDisconnected(adj, 6);

  for (auto i : result)
  {
    cout << i << " ";
  }
  return 0;
}