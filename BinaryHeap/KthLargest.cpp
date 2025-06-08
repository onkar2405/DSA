
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
  int leftIndex = 2 * parentIndex + 1;
  int rightIndex = 2 * parentIndex + 2;

  int maxIndex = parentIndex;
  int size = heap.size();

  if (leftIndex < size && heap[maxIndex] < heap[leftIndex])
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

void buildMaxHeapify(vector<int> &heap)
{
  int n = (heap.size() - 2) / 2;
  for (int i = n; i >= 0; i--)
  {
    maxHeapify(heap, i);
  }
}

void findKthLargest(vector<int> &heap, int k)
{
  buildMaxHeapify(heap);
  for (int i = 0; i < k - 1; i++)
  {
    int size = heap.size() - i;
    swap(heap[0], heap[size - 1]);
    heapify(heap, size, 0);
  }
}

int main()
{
  vector<int> binaryMeanHeap = {4, 8, 16, 11, 2};
  int k = 3;
  findKthLargest(binaryMeanHeap, k);
  printHeap(binaryMeanHeap);
  cout << "kth Largest: " << binaryMeanHeap[0];
  return 0;
}