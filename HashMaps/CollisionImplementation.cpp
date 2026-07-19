#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool isAllDone(vector<int> &result, int size)
{
  return result.size() == size;
}

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
  int rowCount = matrix.size();
  int colCount = matrix[0].size();
  int size = rowCount * colCount;

  vector<int> result;
  int r = 0;
  int c = 0;
  int itr = 0;
  int totalItrs = 0;

  while (true)
  {
    for (c = itr; c < colCount - itr; c++)
    {
      if (isAllDone(result, size))
      {
        return result;
      }
      result.push_back(matrix[r][c]);
    }
    c = c - 1;

    for (r = r + 1; r < rowCount - itr; r++)
    {
      if (isAllDone(result, size))
      {
        return result;
      }
      result.push_back(matrix[r][c]);
    }
    r = r - 1;

    for (c = c - 1; c >= itr; c--)
    {
      if (isAllDone(result, size))
      {
        return result;
      }

      result.push_back(matrix[r][c]);
    }
    c = c + 1;

    for (r = r - 1; r >= itr + 1; r--)
    {
      if (isAllDone(result, size))
      {
        return result;
      }

      result.push_back(matrix[r][c]);
    }
    r = r + 1;

    if (isAllDone(result, size))
    {
      return result;
    }

    itr++;
  }

  return result;
}

int main()
{

  vector<vector<int>> matrix = {{1, 2, 3, 4, 5},
                                {6, 7, 8, 9, 10},
                                {11, 12, 13, 14, 15},
                                {16, 17, 18, 19, 20},
                                {21, 22, 23, 24, 25}};
  vector<int> result = spiralOrder(matrix);

  for (int num : result)
  {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}