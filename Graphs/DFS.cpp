#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfsRecursive(vector<vector<int>> &adj, vector<bool> &isVisited, vector<int> &dfs, int source)
{
  for (int num : adj[source])
  {
    if (!isVisited[num])
    {
      dfs.push_back(num);
      isVisited[num] = true;
      dfsRecursive(adj, isVisited, dfs, num);
    }
  }
}

vector<int> performDfs(vector<vector<int>> &adj, int size)
{
  vector<bool> isVisited(size, false);
  vector<int> dfs;

  dfs.push_back(0);
  isVisited[0] = true;

  for (int i = 0; i < size; i++)
  {
    dfsRecursive(adj, isVisited, dfs, i);
  }

  return dfs;
}

int main()
{
  vector<vector<int>> adj = {{1, 2}, {0, 3, 4}, {0, 3}, {1, 2}, {1, 5}, {4}};

  vector<int> dfs = performDfs(adj, 7);

  for (int i = 0; i < dfs.size(); i++)
  {
    cout << dfs[i] << " ";
  }

  return 0;
}