#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool dfsRecursive(vector<vector<int>> &adj, vector<bool> isVisited, int source, int parent)
{
  isVisited[source] = true;

  for (int i : adj[source])
  {
    if (!isVisited[i])
    {
      if (dfsRecursive(adj, isVisited, i, source) == true)
      {
        return true;
      }
    }
    else if (i != parent)
    {
      return true;
    }
  }

  return false;
}

bool isCyclicGraphDfs(vector<vector<int>> &adj, int size)
{

  vector<bool> isVisited(size, false);

  for (int i = 0; i < size; i++)
  {
    if (!isVisited[i])
    {
      if (dfsRecursive(adj, isVisited, i, -1) == true)
      {
        return true;
      }
    }
  }

  return false;
}

bool isCyclicGraphBfs(vector<vector<int>> &adj, int size)
{
  vector<bool> isVisited(size, false);
  queue<pair<int, int>> nodes;

  for (int start = 0; start < size; start++)
  {
    if (!isVisited[start])
    {
      nodes.push({start, -1});

      while (!nodes.empty())
      {
        int source = nodes.front().first;
        int parent = nodes.front().second;

        nodes.pop();
        isVisited[source] = true;

        for (int i : adj[source])
        {
          if (!isVisited[i])
          {
            isVisited[i] = true;
            nodes.push({i, source});
          }
          else if (i != parent)
          {
            return true;
          }
        }
      }
    }
  }

  return false;
}

int main()
{
  vector<vector<int>> edges = {{1, 2}, {0}, {0}};
  // int size = 6;

  cout << isCyclicGraphDfs(edges, edges.size());
  cout << " " << isCyclicGraphBfs(edges, edges.size());

  return 0;
}