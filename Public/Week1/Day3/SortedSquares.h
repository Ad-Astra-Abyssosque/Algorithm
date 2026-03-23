//
// Created by wcx on 2026/2/3.
//

#ifndef ALGORITHM_SORTEDSQUARES_H
#define ALGORITHM_SORTEDSQUARES_H
#include <vector>

class SortedSquares {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        std::vector<int> result = std::vector<int>(nums.size());
        for (int i = nums.size() - 1, head = 0, tail = nums.size() - 1; tail >= head; i--) {
            int squareHead = nums[head] * nums[head];
            int squareTail = nums[tail] * nums[tail];
            if (squareHead < squareTail) {
                result[i] = squareTail;
                tail--;
            }
            else {
                result[i] = squareHead;
                head++;
            }
        }
        return result;
    }
};

#endif //ALGORITHM_SORTEDSQUARES_H