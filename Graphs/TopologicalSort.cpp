#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

void topologicalSort(vector<vector<int>> &edges, int size)
{
  vector<int> inDegree(size, 0);
  queue<int> q;

  // Creating inDegree
  for (int i = 0; i < size; i++)
  {
    for (int j : edges[i])
    {
      inDegree[j]++;
    }
  }

  // Passing all nodes with 0 indegrees
  for (int i = 0; i < inDegree.size(); i++)
  {
    if (inDegree[i] == 0)
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
      if (inDegree[i] > 0)
      {
        inDegree[i]--;
      }
      if (inDegree[i] == 0)
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