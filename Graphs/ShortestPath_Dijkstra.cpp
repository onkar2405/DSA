#include <iostream>
#include <vector>
using namespace std;

vector<int> findShortest(vector<vector<int>> &edges, int size)
{
  vector<int> result(size, INT_MAX);
  vector<int> isVisited(size, false);
  result[0] = 0;
  for (int i = 0; i < size; i++)
  {

    int u = -1;

    for (int j = 0; j < size; j++)
    {
      if (!isVisited[j] && (u == -1 || result[j] < result[u]))
      {
        u = j;
      }
    }

    for (int k = 0; k < size; k++)
    {
      if (edges[u][k] != 0 && result[k] > result[u] + edges[u][k])
      {
        result[k] = result[u] + edges[u][k];
      }
    }

    isVisited[u] = true;
  }

  return result;
}

int main()
{
  vector<vector<int>> edges = {
      {0, 4, 8, 0, 0, 0, 0, 0, 0}, {4, 0, 11, 8, 0, 0, 0, 0, 0}, {8, 11, 0, 0, 7, 1, 0, 0, 0}, {0, 8, 0, 0, 2, 0, 7, 4, 0}, {0, 0, 7, 2, 0, 6, 0, 0, 0}, {0, 0, 1, 0, 6, 0, 0, 2, 0}, {0, 0, 0, 7, 0, 0, 0, 14, 9}, {0, 0, 0, 4, 0, 2, 14, 0, 10}, {0, 0, 0, 0, 0, 0, 9, 10, 0}};

  int size = 9;

  vector<int> res = findShortest(edges, size);

  for (int i = 0; i < size; i++)
  {
    cout << res[i] << " ";
  }

  return 0;
}
