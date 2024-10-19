#include <iostream>
#include <vector>
using namespace std;

void mergeOptimal(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
  int i = m - 1;
  int j = n - 1;
  int k = m + n - 1;

  while (j >= 0)
  {
    if (i >= 0 && nums1[i] > nums2[j])
    {
      nums1[k--] = nums1[i--];
    }
    else
    {
      nums1[k--] = nums2[j--];
    }
  }
}

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
  vector<int> nums3;
  int i = 0;
  int j = 0;
  if (n == 0)
  {
    return;
  }
  while (i < m + n && j < n)
  {
    if (i < m)
    {
      if (nums1[i] <= nums2[j])
      {
        nums3.push_back(nums1[i]);
        i++;
      }
      else
      {
        nums3.push_back(nums2[j]);
        j++;
      }
    }
    else
    {
      nums3.push_back(nums2[j]);
      j++;
      i++;
    }
  }

  if (j == n)
  {
    while (i < m)
    {
      nums3.push_back(nums1[i]);
      i++;
    }
  }

  nums1 = nums3;
}

int main()
{
  vector<int> vec1 = {-1, 0, 0, 3, 3, 3, 0, 0, 0};
  vector<int> vec2 = {1, 2, 2};

  merge(vec1, vec1.size(), vec2, vec2.size());
}