#include <iostream>
#include <vector>
using namespace std;

void heapifiedMap(vector<int> &binaryHeap, int currentIndex)
{
  int parentValue = binaryHeap[currentIndex];
  int leftIndex = 2 * currentIndex + 1;
  int rightIndex = 2 * currentIndex + 2;
  int smallest = currentIndex;
  if (leftIndex < binaryHeap.size() && parentValue > binaryHeap[leftIndex])
  {
    smallest = leftIndex;
  }

  if (rightIndex < binaryHeap.size() && parentValue > binaryHeap[rightIndex])
  {
    smallest = rightIndex;
  }

  if (smallest != currentIndex)
  {
    swap(binaryHeap[currentIndex], binaryHeap[smallest]);
    heapifiedMap(binaryHeap, smallest);
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
  vector<int> binaryMeanHeap = {40, 20, 30, 35, 25, 80, 32, 100, 70, 60};

  printHeap(binaryMeanHeap);
  heapifiedMap(binaryMeanHeap, 0);
  printHeap(binaryMeanHeap);
  return 0;
}