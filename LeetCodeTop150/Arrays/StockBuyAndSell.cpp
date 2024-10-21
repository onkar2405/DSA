#include <iostream>
#include <vector>
using namespace std;

/**
 * Problem URL: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/?envType=study-plan-v2&envId=top-interview-150
 */
int maxProfit(vector<int> &prices)
{
  int minStockPrice = prices[0];
  int maxProfit = 0;
  for (int i = 1; i < prices.size(); i++)
  {
    if (prices[i] < minStockPrice)
    {
      minStockPrice = prices[i];
    }

    if (prices[i] - minStockPrice > 0)
    {
      maxProfit = max(prices[i] - minStockPrice, maxProfit);
    }
  }

  return maxProfit;
}

int main()
{
  vector<int> nums = {7, 1, 5, 3, 6, 4};

  cout << maxProfit(nums);

  return 0;
}