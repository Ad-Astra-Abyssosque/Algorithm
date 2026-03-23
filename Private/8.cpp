//
// Created by wcx on 2026/3/23.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

static int main1()
{
    vector<int> nums;
    int target;
    pair<int, int> ans;

    unordered_map<int, int> hashtable;
    for (int i = 0; i < nums.size(); ++i) {
        auto it = hashtable.find(target - nums[i]);
        if (it != hashtable.end()) {
            ans = {it->second, i};
        }
        hashtable[nums[i]] = i;
    }

    cout << ans.first << ans.second << endl;
}