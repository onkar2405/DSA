#include <iostream>
#include <vector>
using namespace std;

int getViolatingIndex(vector<int> binaryHeap, int currentLevel)
{
  if (currentLevel >= binaryHeap.size())
  {
    return binaryHeap.size() - 1;
  }

  int parentValue = binaryHeap[currentLevel];
  int leftIndex = 2 * currentLevel + 1;
  int leftVal = binaryHeap[leftIndex];
  int rightIndex = 2 * currentLevel + 2;
  int rightVal = binaryHeap[rightIndex];

  int minOfAll = min(parentValue, min(leftVal, rightVal));

  if (minOfAll != parentValue)
  {
    // return minOfAll==leftVal ? leftIndex : rightIndex;
    return parentValue;
  }

  return getViolatingIndex(binaryHeap, currentLevel + 1);
}

void printHeap(vector<int> binaryHeap)
{
  for (int i = 0; i < binaryHeap.size(); i++)
  {
    cout << binaryHeap[i] << " ";
  }

  cout << "\n";
}

int main()
{
  // vector<int> binaryMeanHeap = {40, 20, 30, 35, 25, 80, 32, 100, 70, 60};
  vector<int> binaryMeanHeap = {10, 15, 30, 35, 60, 80, 32, 100, 70, 25};

  printHeap(binaryMeanHeap);
  cout << getViolatingIndex(binaryMeanHeap, 0);
  return 0;
}