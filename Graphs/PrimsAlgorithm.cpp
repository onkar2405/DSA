#include <iostream>
#include <vector>
#include <set>
using namespace std;

int createMST(vector<vector<int>> &g, int size)
{
  vector<int> keys(size, INT_MAX);
  int result = 0;
  vector<int> msp(size, false);
  keys[0] = 0;

  for (int i = 0; i < size; i++)
  {
    int u = -1;

    for (int j = 0; j < size; j++)
    {
      if (!msp[j] && (u == -1 || keys[u] > keys[i]))
      {
        u = i;
      }
    }

    result = result + keys[u];
    msp[u] = true;

    for (int k = 0; k < size; k++)
    {
      if (!msp[k] && g[u][k] != 0)
      {
        keys[k] = min(keys[k], g[u][k]);
      }
    }
  }

  return result;
}

int main()
{
  vector<vector<int>> g = {{0, 2, 0, 6, 0},
                           {2, 0, 3, 8, 5},
                           {0, 3, 0, 0, 7},
                           {6, 8, 0, 0, 0},
                           {0, 5, 7, 0, 0}};

  vector<vector<int>> g1 = {{0, 5, 8, 0},
                            {5, 0, 10, 15},
                            {8, 10, 0, 20},
                            {0, 15, 20, 0}};

  cout << createMST(g, 5) << " ";
  cout << createMST(g1, 4) << " ";

  return 0;
}