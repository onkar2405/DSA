#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void dfs(vector<vector<int>> &edges, stack<int> &result, int source, vector<int> &isVisited)
{
  isVisited[source] = true;
  for (int j : edges[source])
  {
    if (!isVisited[j])
    {
      isVisited[j] = true;
      dfs(edges, result, j, isVisited);
    }
  }

  result.push(source);
}

void topologicalSort(vector<vector<int>> &edges, int size)
{
  stack<int> result;
  vector<int> isVisited(size, false);

  for (int i = 0; i < size; i++)
  {
    if (!isVisited[i])
    {
      dfs(edges, result, i, isVisited);
    }
  }

  while (!result.empty())
  {
    cout << result.top() << " ";
    result.pop();
  }
}

int main()
{
  vector<vector<int>> ex1 = {{1}, {3}, {3, 4}, {4}, {}};
  topologicalSort(ex1, 5);
  return 0;
}