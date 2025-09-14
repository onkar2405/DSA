#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool dfsRecursive(vector<vector<int>> &adj, vector<bool> &isVisited, vector<bool> &recursiveStack, int source)
{
  isVisited[source] = true;
  recursiveStack[source] = true;

  for (int i : adj[source])
  {
    if (!isVisited[i] && dfsRecursive(adj, isVisited, recursiveStack, i))
    {
      return true;
    }

    if (recursiveStack[i])
    {
      return true;
    }
  }

  recursiveStack[source] = false;

  return false;
}

bool isCyclicGraphDfs(vector<vector<int>> &adj, int size)
{

  vector<bool> isVisited(size, false);
  vector<bool> recursiveStack(size, false);

  for (int i = 0; i < size; i++)
  {
    if (!isVisited[i])
    {
      if (dfsRecursive(adj, isVisited, recursiveStack, i) == true)
      {
        return true;
      }
    }
  }

  return false;
}

int main()
{
  vector<vector<int>> edges = {{1}, {2}, {1}};

  cout << isCyclicGraphDfs(edges, edges.size());

  return 0;
}