#include <iostream>
using namespace std;

/**
 * Digital sum:
 * I/P: 532
 * O/P: 1 ; (5+3+2 => 10 => 1)
 */
int digitalRoot(long long int n)
{
  // Your code here
  if (n < 10)
  {
    return n;
  }

  return digitalRoot(n % 10 + digitalRoot(n / 10));
}

int main()
{
  cout << digitalRoot(257520643643);
  return 0;
}