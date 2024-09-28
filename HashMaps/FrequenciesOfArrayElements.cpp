#include <iostream>
#include <unordered_map>
using namespace std;

void findDistinct(int *inputArray, int size)
{
  unordered_map<int, int> elementCountMap;

  for (int i = 0; i < size; i++)
  {
    if (elementCountMap.find(inputArray[i]) == elementCountMap.end())
    {
      elementCountMap[inputArray[i]] = 1;
    }
    else
    {
      elementCountMap[inputArray[i]] = elementCountMap[inputArray[i]] + 1;
    }
  }

  int distinctCount = 0;
  for (auto x : elementCountMap)
  {
    cout << "\n"
         << x.first << ": " << x.second;
  }
}

int main()
{

  int inputArray[10] = {12, 12, 11, 12, 11, 14, 10, 22, 23, 24};

  findDistinct(inputArray, 10);

  return 0;
}