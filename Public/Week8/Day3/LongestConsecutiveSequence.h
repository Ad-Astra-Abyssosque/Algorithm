//
// Created by yoimiya on 2026/11/13.
//

#ifndef ALGORITHM_LONGESTCONSECUTIVESEQUENCE_H
#define ALGORITHM_LONGESTCONSECUTIVESEQUENCE_H
#include <map>
#include <unordered_map>
#include "../../../Solution.h"

using namespace std;

class LongestConsecutiveSequence: public Solution {
    int longestConsecutive(vector<int>& nums) {
        map<int, bool> table;
        for (int num: nums) {
            table[num] = true;
        }

        int ans = 0;
        auto it = table.begin();

        while (it != table.end()) {
            int tmp = 0;
            int lastNum = 0;
            do {
                tmp++;
                lastNum = it->first;
                ++it;
            } while (it != table.end() && it->first == lastNum + 1);
            ans = max(ans, tmp);
        }

        return ans;
    }

    int longestConsecutive2(vector<int>& nums) {
        unordered_map<int, bool> table;
        for (int num: nums) {
            table[num] = true;
        }

        int ans = 0;
        for (auto& it: table) {
            int num = it.first;
            if (table.find(num - 1) == table.end()) {
                int tmp = 1;
                int x = num;
                while (table.find(x + 1) != table.end()) {
                    ++x;
                    ++tmp;
                }
                ans = max(ans, tmp);
            }
        }
        return ans;
    }
};

#endif //ALGORITHM_LONGESTCONSECUTIVESEQUENCE_H
