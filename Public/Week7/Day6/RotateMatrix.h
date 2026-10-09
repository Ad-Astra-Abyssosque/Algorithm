//
// Created by yoimiya on 2026/7/20.
//

#ifndef ALGORITHM_ROTATEMATRIX_H
#define ALGORITHM_ROTATEMATRIX_H
#include "../../../Solution.h"

using namespace std;

class RotateMatrix: public Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        work(matrix, 0, n);
    }

    void work(vector<vector<int>>& matrix, int start, int n) {
        if (n <= 1) {
            return;
        }

        int x = start, y = start;
        for (int i = 0; i < n - 1; i++) {
            int temp = matrix[x + i][y + n - 1];
            // top left -> top right
            matrix[x + i][y + n - 1] = matrix[x][y + i];
            // bottom left -> top left
            matrix[x][y + i] = matrix[x + n - 1 - i][y];
            // bottom right-> bottom left
            matrix[x + n - 1 - i][y] = matrix[x + n - 1][y + n - 1 - i];
            // top right -> bottom right
            matrix[x + n - 1][y + n - 1 - i] = temp;

            // swap(matrix[x][y + i], matrix[x + i][y + n - 1]);
            // swap(matrix[x][y + i], matrix[x + n - 1][y + n - 1 - i]);
            // swap(matrix[x][y + i], matrix[x + n - 1 - i][y]);

        }
        work(matrix, start + 1, n - 2);
    }
};


#endif //ALGORITHM_ROTATEMATRIX_H
