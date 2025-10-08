#include <iostream>
#include <vector>
using namespace std;

int minimumCoin(vector<int> &coins, int amount)
{
  int minCoins = INT_MAX;

  for (int i = 0; i < coins.size(); i++)
  {
    int tempCoins = amount / coins[i];
    int remainingAmount = amount % coins[i];

    for (int j = 0; j < coins.size(); j++)
    {
      if (j != i && remainingAmount / coins[j] != 0)
      {
        tempCoins += remainingAmount / coins[j];
        remainingAmount = remainingAmount % coins[j];
      }

      if (remainingAmount == 0)
      {
        break;
      }
    }

    minCoins = min(tempCoins, minCoins);
  }

  return minCoins;
}

int main()
{
  vector<int> coins = {5, 10, 2, 1};
  int amount = 45;

  cout << minimumCoin(coins, amount);

  return 0;
}