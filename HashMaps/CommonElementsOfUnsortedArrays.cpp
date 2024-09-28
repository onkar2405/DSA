#include <iostream>
#include <unordered_set>
using namespace std;

void findCommonElements(int *array1, int *array2, int len1, int len2)
{
  unordered_set<int> commonElements;

  for (int i = 0; i < len2; i++)
  {
    commonElements.insert(array2[i]);
  }

  for (int i = 0; i < len1; i++)
  {
    if (commonElements.find(array1[i]) != commonElements.end())
    {
      cout << array1[i] << " ";
    }
  }
}

int main()
{
  int array1[] = {10, 20, 30};
  int array2[] = {30, 10, 20};

  findCommonElements(array1, array2, 3, 3);
}