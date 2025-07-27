#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int MIN_DIFF = INT_MAX;
unordered_map<int, int> diffMap;

void printHeap(vector<int> binaryHeap)
{
  for (int i = 0; i < binaryHeap.size(); i++)
  {
    cout << binaryHeap[i] << " ";
  }

  cout << "\n";
}

void buildMaxHeap(vector<int> &result, int index)
{
  int parentVal = result[index];
  int leftInd = 2 * index + 1;
  int rightInd = 2 * index + 2;
  int maxIndex = index;

  if (leftInd < result.size() && diffMap[result[maxIndex]] < diffMap[result[leftInd]])
  {
    maxIndex = leftInd;
  }
  if (rightInd < result.size() && diffMap[result[maxIndex]] < diffMap[result[rightInd]])
  {
    maxIndex = rightInd;
  }
  if (maxIndex != index)
  {
    swap(result[maxIndex], result[index]);
    buildMaxHeap(result, maxIndex);
  }
}

void updateMaxHeap(vector<int> &result, int num, int x)
{
  int diff = abs(num - x);
  if (diff < diffMap[result[0]])
  {
    result[0] = num;
    int lastRootIndex = (result.size() - 2) / 2;
    buildMaxHeap(result, lastRootIndex < 0 ? 0 : lastRootIndex);
  }
}

vector<int> findKClosest(vector<int> &nums, int k, int x)
{
  vector<int> result;

  for (int i = 0; i < k; i++)
  {
    int diff = abs(nums[i] - x);
    diffMap[nums[i]] = diff;
    result.push_back(nums[i]);
  }

  int lastRootIndex = (result.size() - 2) / 2;
  buildMaxHeap(result, lastRootIndex < 0 ? 0 : lastRootIndex);

  for (int i = k; i < nums.size(); i++)
  {
    int diff = abs(nums[i] - x);
    diffMap[nums[i]] = diff;
    updateMaxHeap(result, nums[i], x);
  }
  return result;
}

int main()
{
  vector<int> nums = {30, 40, 32, 33, 36, 37};
  int k = 1;
  int x = 40;
  vector<int> result(3);

  result = findKClosest(nums, k, x);
  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }
  return 0;
}