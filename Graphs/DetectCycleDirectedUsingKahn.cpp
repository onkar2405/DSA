#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

bool detectCycle(vector<vector<int>> edges, int size)
{
  vector<int> inDrgree(size, 0);
  queue<int> q;

  for (int i = 0; i < size; i++)
  {
    for (int j : edges[i])
    {
      inDrgree[j]++;
    }
  }

  for (int i = 0; i < inDrgree.size(); i++)
  {
    if (inDrgree[i] == 0)
    {
      q.push(i);
    }
  }

  int count = 0;

  while (!q.empty())
  {
    int num = q.front();
    q.pop();
    count++;

    for (int i : edges[num])
    {
      inDrgree[i]--;
      if (inDrgree[i] == 0)
      {
        q.push(i);
      }
    }
  }

  return count != size;
}

int main()
{
  vector<vector<int>> ex1 = {{1}, {2}, {3}, {1}, {1}};

  cout << detectCycle(ex1, 5) << "\n";

  return 0;
}