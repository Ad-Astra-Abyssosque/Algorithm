//
// Created by wcx on 2026/2/13.
//

#ifndef ALGORITHM_LARGESTRECTINHISTOGRAM_H
#define ALGORITHM_LARGESTRECTINHISTOGRAM_H

#include <limits.h>
#include <stack>
#include <vector>
using namespace std;

class LargestRectInHistogram
{
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left = vector<int>(heights.size());
        vector<int> right = vector<int>(heights.size());

        // find left
        stack<pair<int, int>> st_left;
        st_left.push({-1, -1});
        for (int i = 0; i < heights.size(); i++)
        {
            while (heights[i] <= st_left.top().first)
            {
                st_left.pop();
            }
            left[i] = st_left.top().second + 1;
            st_left.push({heights[i], i});
        }

        // find right
        stack<pair<int, int>> st_right;
        st_right.push({-1, heights.size()});
        for (int i = heights.size() - 1; i >= 0; i--)
        {
            while (heights[i] <= st_right.top().first)
            {
                st_right.pop();
            }
            right[i] = st_right.top().second - 1;
            st_right.push({heights[i], i});
        }

        int max_area = INT_MIN;
        for (int i = 0; i < heights.size(); i++)
        {
            int area = heights[i] * (right[i] - left[i] + 1);
            max_area = max(max_area, area);
        }
        return max_area;
    }
};

#endif //ALGORITHM_LARGESTRECTINHISTOGRAM_H