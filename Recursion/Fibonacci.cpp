#include <iostream>
using namespace std;

int fibonacci(int n)
{
  // 0 1 1 2 3 5 8
  if (n == 0 || n == 1)
  {
    return n;
  }

  return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
  int n;

  cout << "Enter Number: ";
  cin >> n;

  cout << "\nFibonacci is: " << fibonacci(n);

  return 0;
}