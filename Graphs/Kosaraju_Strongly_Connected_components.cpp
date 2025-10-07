#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void performKosaraju(vector<vector<int>> &edges, int size)
{
}

int main()
{
  vector<vector<int>> edges = {{0, 0, 1, 0, 0}, {1, 0, 0, 0, 0}, {0, 1, 0, 1, 0}, {0, 0, 0, 0, 1}, {0, 0, 0, 1, 0}};
  int size = 5;

  performKosaraju(edges, size);

  return 0;
}