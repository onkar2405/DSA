/**
 * Input: n=5(Total rope length) ; a=2, b=5, c=1(cut lengths)
 *
 * Output: 5. We make 5 pieces of the rope of length 1 each
 */

#include <iostream>
using namespace std;

int totalCuts(int n, int a, int b, int c)
{

  if (n == 0)
  {
    return 0;
  }
  if (n < 0)
  {
    return -1;
  }

  int res = max(
      max(totalCuts(n - a, a, b, c),
          totalCuts(n - b, a, b, c)),
      totalCuts(n - c, a, b, c));

  if (res == -1)
  {
    return -1;
  }

  return res + 1;
}

int main()
{
  int n;
  int a;
  int b;
  int c;

  cin >> n;
  cin >> a;
  cin >> b;
  cin >> c;

  cout << totalCuts(n, a, b, c);
  return 0;
}