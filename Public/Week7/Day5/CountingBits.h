//
// Created by yoimiya on 2026/7/23.
//

#ifndef ALGORITHM_COUNTINGBITS_H
#define ALGORITHM_COUNTINGBITS_H
#include "../../../Solution.h"

using namespace std;

class CountingBits: public Solution {
public:
    /**
     * 解法一：动态规划——最高有效位
     * @param n
     * @return
     */
    vector<int> countBits(int n) {
        int magic_num = 0;
        int next_maigc_num = 2;
        vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            if (i != next_maigc_num) {
                ans[i] = ans[i - magic_num] + 1;
            }
            else {
                ans[i] = 1;
                magic_num = next_maigc_num;
                next_maigc_num *= 2;
            }
        }
        return ans;
    }

    /**
     * 解法一：动态规划——最低有效位
     * @param n
     * @return
     */
    vector<int> countBits2(int n) {
        vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            ans[i] = ans[i >> 2] + i & 1;
        }
        return ans;
    }
};
#endif //ALGORITHM_COUNTINGBITS_H
