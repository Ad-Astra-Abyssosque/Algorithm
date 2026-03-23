//
// Created by wcx on 2026/2/27.
//

#ifndef ALGORITHM_BESTTIMETOSELLSTOCK2_H
#define ALGORITHM_BESTTIMETOSELLSTOCK2_H

#include <vector>

class BestTimeToSellStock2
{
public:
    int maxProfit_n2(std::vector<int>& prices) {
        std::vector<int> f = std::vector<int>(prices.size(), 0);
        for (int i = 1; i < prices.size(); i++) {
            for (int j = 0; j < i; j++)
            {
                int profit_when_buy_j_sell_i = std::max(0, prices[i] - prices[j]);
                f[i] = std::max(f[i], f[j] + profit_when_buy_j_sell_i);
            }
        }
        return f[prices.size() - 1];
    }

    int maxProfit_Dynamic_n(std::vector<int>& prices) {

        // 之前的某一天结束时，买了股票，然后的最大利润
        int previous_buy = -prices[0];

        // 之前的某一天结束时，卖了股票，此时的最大利润
        int previous_sell = 0;

        for (int i = 1; i < prices.size(); i++)
        {
            int sell_profit = std::max(previous_sell, previous_buy + prices[i]);
            int buy_profit = std::max(previous_buy, previous_sell - prices[i]);
            previous_sell = sell_profit;
            previous_buy = buy_profit;
        }
        return previous_sell;
    }

    int maxProfit_Greedy_n(std::vector<int>& prices)
    {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[i - 1])
            {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }

};

#endif //ALGORITHM_BESTTIMETOSELLSTOCK2_H