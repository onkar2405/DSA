#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &heap, int parentIndex)
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

  swap(heap[parentIndex], heap[maxIndex]);
}

void maxHeap(vector<int> &heap)
{
  int n = (heap.size() - 2) / 2;

  for (int i = n; i >= 0; i--)
  {
    heapify(heap, i);
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
  vector<int> binaryMeanHeap = {100, 15, 50, 4, 39990, 400, 250, 1000, 20};

  printHeap(binaryMeanHeap);

  maxHeap(binaryMeanHeap);
  printHeap(binaryMeanHeap);
  cout << "\nLargest: " << binaryMeanHeap[0];

  return 0;
}