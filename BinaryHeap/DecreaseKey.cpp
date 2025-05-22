#include <iostream>
#include <vector>
using namespace std;

void decreaseKey(vector<int> &minHeap, int index, int val)
{
  int parentIndex = (index - 1) / 2;
  int parentVal = minHeap[parentIndex];

  if (parentIndex >= 0 && parentVal > val)
  {
    swap(minHeap[parentIndex], minHeap[index]);
    decreaseKey(minHeap, parentIndex, val);
  }
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
  vector<int> minHeap = {10, 20, 40, 80, 100, 70};
  int replaceIndex = 3;
  int replaceVal = 5;

  minHeap[replaceIndex] = replaceVal;
  decreaseKey(minHeap, replaceIndex, replaceVal);
  printHeap(minHeap);
  return 0;
}