#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
using namespace std;

/**
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 */
int maxProfit(vector<int> &prices)
{
  int maxProfit = 0;
  int minStock = prices[0];

  for (int i = 1; i < prices.size(); i++)
  {

    if (minStock > prices[i])
    {
      minStock = prices[i];
    }
    int diff = prices[i] - minStock < 0 ? 0 : prices[i] - minStock;
    maxProfit = max(maxProfit, diff);
  }

  return maxProfit;
}