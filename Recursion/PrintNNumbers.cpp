#include <iostream>
using namespace std;

/**
 * Input: 5
 * output: 5 4 3 2 1
 */
void printNtoOne(int n)
{
  if (n == 0)
  {
    return;
  }
  cout << n << " ";
  printNtoOne(n - 1);
}

/**
 * Input: 5
 * output: 1 2 3 4 5
 */
void printOneN(int n)
{
  if (n == 0)
  {
    return;
  }
  printOneN(n - 1);
  cout << n << " ";
}

int main()
{
  int n;

  cout << "Enter Number: ";
  cin >> n;

  printNtoOne(n);
  cout << "\n";
  printOneN(n);

  return 0;
}