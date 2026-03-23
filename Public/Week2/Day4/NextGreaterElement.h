//
// Created by wcx on 2026/2/13.
//

#ifndef ALGORITHM_NEXTGREATERELEMENT_H
#define ALGORITHM_NEXTGREATERELEMENT_H

#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class NextGreaterElement
{
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        vector<int> result = vector<int>(nums1.size(), -1);
        stack<int> st;
        for (int i = nums2.size() - 1; i >= 0; i--)
        {

        }
        return result;
    }
};

#endif //ALGORITHM_NEXTGREATERELEMENT_H