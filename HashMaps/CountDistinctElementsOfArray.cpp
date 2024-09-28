#include <iostream>
#include <unordered_set>
using namespace std;

int findDistinct(int *inputArray, int size)
{
  /**
   * Solved this using set because set doesn't allow duplicates, it always contains distinct values in it.
   */
  unordered_set<int> distinctElements;

  for (int i = 0; i < size; i++)
  {
    distinctElements.insert(inputArray[i]);
  }

  return distinctElements.size();
}

int main()
{

  int inputArray[10] = {12, 12, 11, 12, 11, 14, 10, 22, 23, 24};
  int inputArray1[7] = {15, 12, 13, 12, 13, 13, 18};

  cout << findDistinct(inputArray, 10) << "\n";
  cout << findDistinct(inputArray1, 7);

  return 0;
}