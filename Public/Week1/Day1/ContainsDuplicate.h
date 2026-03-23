//
// Created by wcx on 2026/2/1.
//

#ifndef ALGORITHM_CONTAINSDUPLICATE_H
#define ALGORITHM_CONTAINSDUPLICATE_H


#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class ContainsDuplicate {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> set;
        for (int i = 0; i < nums.size(); i++) {
            auto pair = set.insert(nums[i]);
            if (!pair.second) {
                return true;
            }
        }
        return false;
    }

    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            auto pair = map.insert({nums[i], i});
            if (!pair.second) {
                if (i - map[nums[i]] <= k) {
                    return true;
                }
                else {
                    map[nums[i]] = i;
                }
            }
        }
        return false;
    }
};

#endif //ALGORITHM_CONTAINSDUPLICATE_H