//
// Created by wcx on 2026/3/18.
//

#ifndef ALGORITHM_COINCHANGE_H
#define ALGORITHM_COINCHANGE_H
#include "../../../Solution.h"

using namespace std;

class CoinChange: Solution
{
public:
    int coinChange(std::vector<int>& coins, int amount) {
        vector<int> coin_num(amount + 1, -1);
        coin_num[0] = 0;
        for (int& coin: coins)
        {
            if (coin < amount) { coin_num[coin] = 1; }
        }


        for (int i = 1; i < amount; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                if (i - coins[j] >= 0 && coin_num[i - coins[j]] != -1)
                {
                    if (coin_num[i] == -1) { coin_num[i] = coin_num[i - coins[j]] + 1; }
                    else
                    {
                        coin_num[i] = min(coin_num[i], coin_num[i - coins[j]] + 1);
                    }
                }
            }
        }
        return coin_num[amount];
    }
};

#endif //ALGORITHM_COINCHANGE_H