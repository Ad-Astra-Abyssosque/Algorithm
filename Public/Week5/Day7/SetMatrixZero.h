//
// Created by wcx on 2026/3/30.
//

#ifndef ALGORITHM_SETMATRIXZERO_H
#define ALGORITHM_SETMATRIXZERO_H
#include "../../../Solution.h"
using namespace std;

class SetMatrixZero: public Solution
{
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> rows;
        vector<int> cols;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }

        for (int& row: rows)
        {
            for (int i = 0; i < n; i++)
            {
                matrix[row][i] = 0;
            }
        }
        for (const int& col: cols)
        {
            for (int j = 0; j < m; j++)
            {
                matrix[j][col] = 0;
            }
        }

    }
};

#endif //ALGORITHM_SETMATRIXZERO_H