#include <iostream>
#include <vector>
using namespace std;

vector<int> insertInHeap(vector<int> binaryHeap, int val, int currentIndex)
{
  if (currentIndex <= 0)
  {
    return binaryHeap;
  }
  int parentIndex = (currentIndex - 1) / 2;
  int parentValue = binaryHeap[parentIndex];

  if (parentValue > val)
  {
    swap(binaryHeap[currentIndex], binaryHeap[parentIndex]);
    insertInHeap(binaryHeap, val, parentIndex);
  }
  return binaryHeap;
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
  vector<int> binaryMeanHeap = {10, 20, 15, 40, 50, 100, 25, 45};

  printHeap(binaryMeanHeap);
  binaryMeanHeap.push_back(12);
  binaryMeanHeap = insertInHeap(binaryMeanHeap, 12, binaryMeanHeap.size() - 1);
  printHeap(binaryMeanHeap);

  return 0;
}