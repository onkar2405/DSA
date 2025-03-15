#include <iostream>
#include <vector>
using namespace std;

/**
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/submissions/1574504895/?envType=study-plan-v2&envId=top-interview-150
 */
int maxProfit(vector<int> &prices)
{
  int totalProfit = 0;
  int stockBought = prices[0];

  for (int i = 1; i < prices.size(); i++)
  {
    if (stockBought >= prices[i])
    {
      stockBought = prices[i];
      continue;
    }
    int diff = prices[i] - stockBought;
    totalProfit += diff;
    stockBought = prices[i];
  }
  return totalProfit;
}