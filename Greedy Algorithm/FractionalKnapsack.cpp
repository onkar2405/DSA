#include <iostream>
#include <vector>
using namespace std;

void sortWeights(vector<vector<int>> &weights)
{
  for (int i = 0; i < weights.size(); i++)
  {
    int min = i;

    for (int j = i; j < weights.size(); j++)
    {
      if (weights[j][0] < weights[min][0])
      {
        min = j;
      }
    }

    swap(weights[i], weights[min]);
  }
}

int fractionalKnapsack(vector<vector<int>> &weights, int capacity)
{
  int result = 0;

  sortWeights(weights);

  int i;
  for (i = 0; i < weights.size(); i++)
  {
    if (capacity - weights[i][0] <= 0)
    {
      break;
    }
    result += weights[i][1];
    capacity -= weights[i][0];
  }

  if (capacity > 0)
  {
    int remainingWeight = (capacity * weights[i][1]) / weights[i][0];
    result += remainingWeight;
  }
  return result;
}

int main()
{
  vector<vector<int>> weights = {{50, 600}, {20, 500}, {30, 400}};
  int capacity = 70;

  cout << fractionalKnapsack(weights, capacity);
  return 0;
}