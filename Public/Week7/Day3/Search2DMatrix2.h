//
// Created by yoimiya on 2026/7/20.
//

#ifndef ALGORITHM_SEARCH2DMATRIX2_H
#define ALGORITHM_SEARCH2DMATRIX2_H

#include "../../../Solution.h"

using namespace std;

class Search2DMatrix2 : public Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int x = 0;
        int y = n - 1;

        while (x < m && y >= 0) {
            if (matrix[x][y] > target) {
                y--;
            }
            else if (matrix[x][y] < target) {
                x++;
            }
            else {
                return true;
            }
        }
        return false;
    }
};

#endif //ALGORITHM_SEARCH2DMATRIX2_H
