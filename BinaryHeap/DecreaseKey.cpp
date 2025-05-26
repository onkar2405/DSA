#include <iostream>
#include <vector>
using namespace std;

int MINUS_INFINITY = -5;

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

void replaceKeyWithMinusInfi(vector<int> &minHeap, int index)
{
  if (index > 0)
  {
    int parentIndex = (index - 1) / 2;
    int parentVal = minHeap[parentIndex];
    if (parentVal > minHeap[index])
    {
      swap(minHeap[index], minHeap[parentIndex]);
      replaceKeyWithMinusInfi(minHeap, parentIndex);
    }
  }
}

void heapify(vector<int> &minHeap, int index)
{
  int leftIndex = 2 * index + 1;
  int rightIndex = 2 * index + 2;
  int minIndex = index;
  if (leftIndex < minHeap.size() && minHeap[minIndex] > minHeap[leftIndex])
  {
    minIndex = leftIndex;
  }
  if (rightIndex < minHeap.size() && minHeap[minIndex] > minHeap[rightIndex])
  {
    minIndex = rightIndex;
  }
  if (minIndex != index)
  {
    swap(minHeap[minIndex], minHeap[index]);
    heapify(minHeap, minIndex);
  }
}

int main()
{
  vector<int> minHeap = {10, 20, 40, 80, 100, 70};
  int replaceIndex = 3;
  int replaceVal = 5;

  minHeap[replaceIndex] = replaceVal;
  decreaseKey(minHeap, replaceIndex, replaceVal);

  int deleteIndex = 3;
  vector<int> minHeap1 = {10, 20, 30, 40, 50, 35, 38, 45};
  minHeap1[deleteIndex] = MINUS_INFINITY;
  printHeap(minHeap1);
  replaceKeyWithMinusInfi(minHeap1, deleteIndex);
  printHeap(minHeap1);
  swap(minHeap1[minHeap1.size() - 1], minHeap1[0]);
  minHeap1.pop_back();
  heapify(minHeap1, 0);
  printHeap(minHeap1);

  return 0;
}