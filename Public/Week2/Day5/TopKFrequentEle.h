//
// Created by wcx on 2026/3/18.
//

#ifndef ALGORITHM_TOPKFREQUENTELE_H
#define ALGORITHM_TOPKFREQUENTELE_H
#include "../../../Solution.h"
#include <unordered_map>

using namespace std;

class TopKFrequentEle: Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;
        for (int& num: nums) {
            frequency[num]++;
        }
        // first: frequency, second: num
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        // for (auto& it: frequency) {
        //     if (min_heap.size() < k) {
        //         min_heap.emplace(it.second, it.first);
        //     }
        //     else if (it.second > min_heap.top().first) {
        //         min_heap.pop();
        //         min_heap.emplace(it.second, it.first);
        //     }
        // }

        // vector<int> ans;
        // while (!min_heap.empty()) {
        //     ans.push_back(min_heap.top().second);
        //     min_heap.pop();
        // }
        // return ans;

        // first: frequency, second: num
        vector<pair<int, int>> array;
        for (auto& it: frequency) {
            array.emplace_back(it.second, it.first);
        }
        quicksort(array, 0, array.size() - 1, k);
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(array[i].second);
        }
        return ans;
    }

    void quicksort(vector<pair<int, int>>& array, int l, int r, int k) {
        if (l >= r) { return; }
        int pos = partition(array, l, r);
        if (k <= pos) { quicksort(array, l, pos, k); }
        else { quicksort(array, pos + 1, r, k); }
        // if (k >= pos) { quicksort(array, pos + 1, r, k); }
    }

    int partition(vector<pair<int, int>>& array, int l, int r) {
        int pivot = array[l].first;
        int i = l - 1;
        int j = r + 1;
        while (i < j) {
            do { i++; } while (array[i].first > pivot);
            do { j--; } while (array[j].first < pivot);
            if (i < j) {
                swap(array[i], array[j]);
            }
        }
        return j;
    }

    virtual void main() override
    {
        vector<int> nums = {3,0,1,0};
        topKFrequent(nums, 1);
    }
};

#endif //ALGORITHM_TOPKFREQUENTELE_H