/**
 * You are given an array prices where prices[i] is the price of a given stock
 on the ith day.

 You want to maximize your profit by choosing a single day to buy one stock and
 choosing a different day in the future to sell that stock.

 Return the maximum profit you can achieve from this transaction. If you cannot
 achieve any profit, return 0.
 */

#include <iostream>
using namespace std;

int maxProfit(vector<int> &prices) {
  int maxProfit = 0;
  int currentMin = prices[0];

  for (int i = 1; i < prices.size(); i++) {
    if (prices[i] < currentMin) {
      currentMin = prices[i];
    } else {
      if (prices[i] - currentMin > maxProfit) {
        maxProfit = prices[i] - currentMin;
      }
    }
  }

  return maxProfit;
}

int main() {
  vector<int> prices;
  //[7,1,5,3,6,4]
  prices.push_back(7);
  prices.push_back(6);
  prices.push_back(5);
  prices.push_back(4);
  prices.push_back(3);
  prices.push_back(2);

  cout << maxProfit(prices) << endl;
}
