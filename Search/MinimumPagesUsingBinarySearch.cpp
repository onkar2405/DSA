#include <iostream>
using namespace std;

int isFeasible(int *arr, int len, int possibleMinPages, int actualGivenStudents)
{
  int sum = 0;
  int studentsRequiredForGivenPossiblePages = 1;
  for (int i = 0; i < len; i++)
  {
    if ((sum + arr[i]) > possibleMinPages)
    {
      sum = arr[i];
      studentsRequiredForGivenPossiblePages++;
    }
    else
    {
      sum += arr[i];
    }
  }

  return studentsRequiredForGivenPossiblePages > actualGivenStudents;
}

int minPages(int *arr, int len, int students)
{
  // Find total sum and maximum number in an array
  int sum = 0;
  int maxNum = INT_MIN;

  for (int i = 0; i < len; i++)
  {
    sum += arr[i];
    maxNum = max(maxNum, arr[i]);
  }

  int low = maxNum;
  int high = sum;
  int possibleMinPages;
  int res = -1;
  while (low <= high)
  {
    possibleMinPages = (low + high) / 2;
    if (!isFeasible(arr, len, possibleMinPages, students))
    {
      res = possibleMinPages;
      high = possibleMinPages - 1;
    }
    else
    {
      low = possibleMinPages + 1;
    }
  }

  return res;
}

int main()
{
  int arr[] = {10, 20, 30, 40, 50};
  int len = 5;
  int students = 2;

  cout << minPages(arr, len, students);

  return 0;
}