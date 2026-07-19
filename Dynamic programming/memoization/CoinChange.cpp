#include <iostream>
#include <vector>
using namespace std;

int coinChangeMemo(vector<int> &c, int size, int sum, vector<vector<int>> &memo)
{

  return memo[size][sum];
}

int coinChange(vector<int> c, int size, int sum)
{
  if (size == 0)
  {
    return 0;
  }

  if (sum == 0)
  {
    return 1;
  }
  if (sum < 0)
  {
    return 0;
  }

  return coinChange(c, size, sum - c[size - 1]) + coinChange(c, size - 1, sum);
}

int main()
{
  int sum = 4;
  vector<int> coins = {1, 2, 3};
  vector<vector<int>> memo(coins.size() + 1, vector<int>(sum + 1, -1));

  // cout << coinChange(coins, coins.size(), sum) << endl;
  cout << coinChangeMemo(coins, coins.size(), sum, memo) << endl;

  return 0;
}