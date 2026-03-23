//
// Created by wcx on 2026/2/5.
//

#ifndef ALGORITHM_THREENUM_H
#define ALGORITHM_THREENUM_H

#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

#include "../../../Solution.h"
using namespace std;

class ThreeSum: public Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> tmp;
        for (int i = 0; i < nums.size(); i++) {
            // 用两数之和的方法做
            std::unordered_map<int, int> map;
            int twoSum = 0 - nums[i];
            for (int j = 0; j < nums.size(); j++) {
                if (j == i) { continue; }
                int target = twoSum - nums[j];
                if (map.find(target) != map.end()) {
                    vector<int> vec = {nums[i], nums[j], nums[map[target]]};
                    sort(vec.begin(), vec.end());
                    tmp.insert(vec);
                }
                else {
                    map[nums[j]] = j;
                }
            }

        }
        return vector<vector<int>>(tmp.begin(), tmp.end());
    }

    vector<vector<int>> threeSumBetter(vector<int>& nums) {
        // set<vector<int>> tmp;
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // 用两数之和的方法做
            std::unordered_map<int, int> map;
            int twoSum = 0 - nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                int target = twoSum - nums[j];
                if (map.find(target) != map.end()) {
                    result.push_back({nums[i], target, nums[j]});
                    // 跳过 j 的重复，避免同一 i 下重复
                    while (j + 1 < nums.size() && nums[j] == nums[j + 1]) j++;
                }
                else {
                    map[nums[j]] = j;
                }
            }

        }
        return result;
        // return vector<vector<int>>(tmp.begin(), tmp.end());
    }

    vector<vector<int>> threeSum_TwoPointer(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int target = - nums[i];
            int start = i + 1;
            int end = nums.size() - 1;
            while (start < end) {
                if (nums[start] + nums[end] < target) {
                    start++;
                }
                else if (nums[start] + nums[end] > target) {
                    end--;
                }
                else {
                    result.push_back({nums[i], nums[start], nums[end]});
                    do { start++; } while (start < nums.size() && nums[start] == nums[start - 1]);
                    do { end--; } while (end >= 0 && nums[end] == nums[end + 1]);
                }
            }
        }
        return result;
    }

    virtual void main() override {
        std::vector<int> nums = {-1,0,1,2,-1,-4};
        auto result = threeSum_TwoPointer(nums);
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }
};

#endif //ALGORITHM_THREENUM_H