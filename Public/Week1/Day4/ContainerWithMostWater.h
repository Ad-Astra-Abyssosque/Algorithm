//
// Created by wcx on 2026/2/5.
//

#ifndef ALGORITHM_CONTAINERWITHMOSTWATER_H
#define ALGORITHM_CONTAINERWITHMOSTWATER_H

#include <vector>

using namespace std;

class ContainerWithMostWater {
public:
    int maxArea_BruteForce(vector<int>& height) {
        // brute force
        int maxArea = 0;
        for (int i = 0; i < height.size(); i++) {
            for (int j = i + 1; j < height.size(); j++) {
                int h = height[i] > height[j] ? height[j] : height[i];
                int area = h * (j - i);
                if (area > maxArea) maxArea = area;
            }
        }
        return maxArea;
    }

    int min(int a, int b) {
        return a < b ? a : b;
    }

    int maxArea(vector<int>& height) {
        // brute force

        int start = 0;
        int end = height.size() - 1;
        int maxArea = 0;
        while (start < end) {
            // if (height[start] < height[end]) {
            //     maxArea = max(maxArea, (end - start) * height[start]);
            //     start++;
            // }
            // else {
            //     maxArea = max(maxArea, (end - start) * height[end]);
            //     end--;
            // }
            // move start
            int areaLeft = 0;
            int areaRight = 0;
            if (start + 1 < end) {
                areaLeft = (end - (start + 1)) * min(height[start + 1], height[end]);
                maxArea = max(maxArea, area);
            }
            // move end
            if (end - 1 > start) {
                areaRight = (end - 1 - start) * min(height[end - 1], height[start]);
                maxArea = max(maxArea, areaRight);
            }
            if (areaLeft > areaRight) {
                start++;
            }
            else {
                end--;
            }
        }
        return maxArea;
    }
};

#endif //ALGORITHM_CONTAINERWITHMOSTWATER_H