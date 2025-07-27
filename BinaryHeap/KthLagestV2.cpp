#include <iostream>
#include <vector>
using namespace std;

int INFINITY = INT_MAX;

void printHeap(vector<int> binaryHeap)
{
  for (int i = 0; i < binaryHeap.size(); i++)
  {
    cout << binaryHeap[i] << " ";
  }

  cout << "\n";
}

void buildMaxHeap(vector<int> &nums, int index)
{
  int parentValue = nums[index];
  int leftInd = index * 2 + 1;
  int rightInd = index * 2 + 2;
  int maxIndex = index;
  if (leftInd < nums.size() && nums[leftInd] > parentValue)
  {
    maxIndex = leftInd;
  }
  if (rightInd < nums.size() && nums[rightInd] > nums[maxIndex])
  {
    maxIndex = rightInd;
  }
  if (maxIndex != index)
  {
    swap(nums[maxIndex], nums[index]);
    buildMaxHeap(nums, maxIndex);
  }
}

void maxHeapify(vector<int> &nums, int index, int size)
{
  int parentValue = nums[index];
  int leftInd = index * 2 + 1;
  int rightInd = index * 2 + 2;
  int maxIndex = index;
  if (leftInd < size && nums[leftInd] > parentValue)
  {
    maxIndex = leftInd;
  }
  if (rightInd < size && nums[rightInd] > nums[maxIndex])
  {
    maxIndex = rightInd;
  }
  if (maxIndex != index)
  {
    swap(nums[maxIndex], nums[index]);
    maxHeapify(nums, maxIndex, size);
  }
}

int findKthLargest(vector<int> &binaryHeap, int k)
{
  int lastRootIndex = (binaryHeap.size() - 2) / 2;
  for (int i = lastRootIndex; i >= 0; i--)
  {
    buildMaxHeap(binaryHeap, i);
  }
  for (int i = 0; i < k - 1; i++)
  {
    int updatedSize = binaryHeap.size() - i;
    swap(binaryHeap[0], binaryHeap[updatedSize - 1]);
    maxHeapify(binaryHeap, 0, updatedSize - 1);
  }

  return binaryHeap[0];
}

int main()
{
  vector<int> binaryMinHeap = {1, 12, 14, 111, 200};
  int k = 3;

  cout << "\nfindKthLargest:" << findKthLargest(binaryMinHeap, k);
  return 0;
}