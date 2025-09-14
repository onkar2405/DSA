#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> getShortest(vector<vector<int>> &edges, int source, int size)
{
  vector<bool> isVisited(size, false);
  vector<int> distance(size, INT_MAX);
  queue<int> q;

  q.push(source);
  isVisited[source] = true;
  distance[source] = 0;

  while (!q.empty())
  {
    int num = q.front();
    q.pop();

    for (int i : edges[num])
    {
      if (!isVisited[i])
      {
        distance[i] = distance[num] + 1;
        isVisited[i] = true;
        q.push(i);
      }
    }
  }

  return distance;
}

int main()
{
  vector<vector<int>> edges = {{1, 2}, {0, 2, 3}, {0, 1, 3}, {1, 3}};
  int source = 0;
  int size = 4;

  vector<int> distance = getShortest(edges, source, size);

  for (int i = 0; i < distance.size(); i++)
  {
    cout << distance[i] << " ";
  }

  return 0;
}