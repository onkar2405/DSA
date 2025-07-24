#include <iostream>
#include <vector>
using namespace std;

int INFINITY = 1000000;

void printHeap(vector<int> binaryHeap)
{
  for (int i = 0; i < binaryHeap.size(); i++)
  {
    cout << binaryHeap[i] << " ";
  }

  cout << "\n";
}

void binaryHeapify(vector<int> &heap, int parentIndex)
{
  int size = heap.size();
  int parentVal = heap[parentIndex];
  int leftIndex = 2 * parentIndex + 1;
  int rightIndex = 2 * parentIndex + 2;
  int minIndex = parentIndex;
  if (leftIndex < size && parentVal > heap[leftIndex])
  {
    minIndex = leftIndex;
  }
  if (rightIndex < size && heap[minIndex] > heap[rightIndex])
  {
    minIndex = rightIndex;
  }

  if (minIndex != parentIndex)
  {
    swap(heap[parentIndex], heap[minIndex]);
    binaryHeapify(heap, minIndex);
  }
}

void heapify(vector<int> &heap)
{
  int size = (heap.size() - 2) / 2;
  for (int i = size; i >= 0; i--)
  {
    binaryHeapify(heap, i);
  }
}

void removeItemFromHeap(vector<int> &heap, int parentIndex)
{

  int size = heap.size() - 1;
  int leftIndex = 2 * parentIndex + 1;
  int rightIndex = 2 * parentIndex + 2;
  int minIndex;
  if (leftIndex > size && rightIndex > size)
  {
    return;
  }

  if (leftIndex > size)
  {
    minIndex = rightIndex;
  }
  else if (rightIndex > size)
  {
    minIndex = leftIndex;
  }
  else
  {
    minIndex = heap[leftIndex] > heap[rightIndex] ? rightIndex : leftIndex;
  }

  if (parentIndex != minIndex)
  {
    swap(heap[parentIndex], heap[minIndex]);
    removeItemFromHeap(heap, minIndex);
  }
}

int findMaxItems(vector<int> &minHeap, int sum)
{
  int items = 0;
  int currentSum = sum;
  while (currentSum > 0)
  {
    currentSum = currentSum - minHeap[0];
    minHeap[0] = INFINITY;
    if (currentSum >= 0)
    {
      items++;
    }
    removeItemFromHeap(minHeap, 0);
    minHeap.pop_back();
  }

  return items;
}

int main()
{
  vector<int> binaryMinHeap = {1, 12, 5, 111, 200};
  int sum = 20;
  heapify(binaryMinHeap);
  cout << findMaxItems(binaryMinHeap, sum);

  return 0;
}