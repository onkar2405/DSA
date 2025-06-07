#include <iostream>
#include <vector>
using namespace std;

void printHeap(vector<int> binaryHeap)
{
  for (int i = 0; i < binaryHeap.size(); i++)
  {
    cout << binaryHeap[i] << " ";
  }

  cout << "\n";
}

void maxHeapify(vector<int> &heap, int parentIndex)
{
  int parentVal = heap[parentIndex];
  int leftIndex = 2 * parentIndex + 1;
  int rightIndex = 2 * parentIndex + 2;
  int maxIndex = parentIndex;
  if (leftIndex < heap.size() && parentVal < heap[leftIndex])
  {
    maxIndex = leftIndex;
  }
  if (rightIndex < heap.size() && heap[maxIndex] < heap[rightIndex])
  {
    maxIndex = rightIndex;
  }

  if (maxIndex != parentIndex)
  {
    swap(heap[parentIndex], heap[maxIndex]);
    maxHeapify(heap, maxIndex);
  }
}

void heapify(vector<int> &heap, int size, int parentIndex)
{
  int parentVal = heap[parentIndex];
  int leftIndex = 2 * parentIndex + 1;
  int rightIndex = 2 * parentIndex + 2;
  int maxIndex = parentIndex;
  if (leftIndex < size && parentVal < heap[leftIndex])
  {
    maxIndex = leftIndex;
  }
  if (rightIndex < size && heap[maxIndex] < heap[rightIndex])
  {
    maxIndex = rightIndex;
  }

  if (maxIndex != parentIndex)
  {
    swap(heap[parentIndex], heap[maxIndex]);
  }
}

void maxHeap(vector<int> &heap)
{
  int n = (heap.size() - 2) / 2;

  for (int i = n; i >= 0; i--)
  {
    maxHeapify(heap, i);
  }
  printHeap(heap);
}

void heapSort(vector<int> &heap)
{
  maxHeap(heap);
  int n = heap.size();
  for (int i = n - 1; i > 0; i--)
  {
    swap(heap[0], heap[i]);
    heapify(heap, i, 0);
  }
}

int main()
{
  vector<int> binaryMeanHeap = {100, 15, 50, 4, 39990, 400, 250, 1000, 20};
  // vector<int> binaryMeanHeap = {10, 15, 50, 4, 20};

  printHeap(binaryMeanHeap);

  heapSort(binaryMeanHeap);
  printHeap(binaryMeanHeap);

  return 0;
}