#include <iostream>
using namespace std;

/**
 * I/P: 245
 * O/P: 2+4+5 = 11
 */
int sumOfDigits(int n)
{
  if (n == 0)
  {
    return 0;
  }

  return n % 10 + sumOfDigits(n / 10);
}

int main()
{
  int n;

  cout << "Enter Number: ";
  cin >> n;

  cout << "\nSum is: " << sumOfDigits(n);

  return 0;
}