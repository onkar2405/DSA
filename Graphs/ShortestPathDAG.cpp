#include <iostream>
#include <vector>
using namespace std;
const int INF = 1000;

void getShortestFromSourceDFS(vector<vector<int>> &edges, int source, int distanceFromSource, vector<int> &result)
{
  for (int i : edges[source])
  {
  }
}

vector<int> getShortest(vector<vector<int>> &edges, int source, int size)
{
  vector<int> result(size, INF);
  int count = 0;

  result[source] = 0;

  for (int i = 0; i < edges.size(); i++)
  {
    getShortestFromSourceDFS(edges, i, count, result);
  }

  return result;
}

int main()
{
  vector<vector<int>> edges = {{1, 2}, {0, 2, 3}, {0, 1, 3}, {1, 3}};
  int source = 0;
  int size = 4;

  vector<int> distance = getShortest(edges, source, size);
}