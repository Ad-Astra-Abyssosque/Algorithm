//
// Created by yoimiya on 2026/11/13.
//

#ifndef ALGORITHM_MAXSLIDINGWINDOW_H
#define ALGORITHM_MAXSLIDINGWINDOW_H

#include "../../../Solution.h"
#include <deque>

using namespace std;

class MaxSlidingWindow: public Solution {
    struct Item {
        int val;
        int index;
        Item(int val_, int index_): val(val_), index(index_) {}
    };

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<Item> dq;
        int start = 0;
        int end = 0;
        while (end < nums.size()) {
            int num = nums[end];
            while (!dq.empty() && num >= dq.back().val) {
                dq.pop_back();
            }
            dq.emplace_back(num, end);

            while (dq.front().index > end || dq.front().index < start) {
                dq.pop_front();
            }

            end++;
            if (end - start == k) {
                ans.push_back(dq.front().val);
                start++;
            }
        }
        return ans;
    }
};
#endif //ALGORITHM_MAXSLIDINGWINDOW_H
