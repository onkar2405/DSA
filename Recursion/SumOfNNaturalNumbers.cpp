#include <iostream>
using namespace std;

int sumOfNaturalNums(int n)
{
  if (n == 1)
  {
    return 1;
  }

  return n + sumOfNaturalNums(n - 1);
}

int main()
{

  int n;

  cin >> n;
  cout << sumOfNaturalNums(n);
  return 0;
}