#include <iostream>
#include <vector>
using namespace std;

void extractMeanHeap(vector<int> &binaryHeap, int currentIndex)
{
  int parentValue = binaryHeap[currentIndex];
  int leftIndex = 2 * currentIndex + 1;
  int rightIndex = 2 * currentIndex + 2;
  int smallest = currentIndex;

  if (leftIndex < binaryHeap.size() && rightIndex < binaryHeap.size())
  {
    smallest = binaryHeap[leftIndex] < binaryHeap[rightIndex] ? leftIndex : rightIndex;
  }

  if (binaryHeap[smallest] > binaryHeap[currentIndex])
  {
    smallest = currentIndex;
  }

  if (smallest != currentIndex)
  {
    swap(binaryHeap[currentIndex], binaryHeap[smallest]);
    extractMeanHeap(binaryHeap, smallest);
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
  vector<int> binaryMeanHeap = {20, 25, 30, 35, 40, 80, 32, 100, 70, 60};

  printHeap(binaryMeanHeap);
  if (binaryMeanHeap.size() > 2)
  {
    swap(binaryMeanHeap[0], binaryMeanHeap[binaryMeanHeap.size() - 1]);
    binaryMeanHeap.pop_back();
  }
  extractMeanHeap(binaryMeanHeap, 0);
  printHeap(binaryMeanHeap);

  return 0;
}