#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

void topologicalSort(vector<vector<int>> &edges, int size)
{
  vector<int> indegrees(size, 0);
  vector<int> result(size);
  vector<int> isVisited(size, false);

  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < edges[i].size(); j++)
    {
      indegrees[edges[i][j]]++;
    }
  }

  queue<int> q;

  for (int i = 0; i < size; i++)
  {
    if (indegrees[i] == 0)
    {
      q.push(i);
    }
  }

  while (!q.empty())
  {
    int num = q.front();
    q.pop();

    cout << num << " ";

    for (int i : edges[num])
    {
      indegrees[i]--;

      if (indegrees[i] == 0)
      {
        q.push(i);
      }
    }
  }
}

int main()
{
  vector<vector<int>> ex1 = {{1, 2}, {}, {}};
  vector<vector<int>> ex2 = {{2, 3}, {3, 4}, {}, {}, {}};
  vector<vector<int>> ex3 = {{2, 3}, {3, 4}, {3}, {}, {}};

  topologicalSort(ex1, 3);

  cout << "\n";
  topologicalSort(ex2, 5);
  cout << "\n";
  topologicalSort(ex3, 5);

  return 0;
}