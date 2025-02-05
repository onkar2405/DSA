#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int> &digits)
{

  for (int i = digits.size() - 1; i >= 0; i--)
  {
    if (digits[i] + 1 != 10)
    {
      digits[i] += 1;

      return digits;
    }
    digits[i] = 0;
  }

  digits.insert(digits.begin(), 1);

  return digits;
}