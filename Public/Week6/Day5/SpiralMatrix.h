//
// Created by wcx on 2026/4/4.
//

#ifndef ALGORITHM_SPIRALMATRIX_H
#define ALGORITHM_SPIRALMATRIX_H
#include "../../../Solution.h"

using namespace std;

class SpiralMatrix: public Solution
{
public:
    vector<int> ans;
    int m;
    int n;

    int getNextDirection(int cur)
    {
        return (cur + 1) % 4;
    }

    bool isValid(const vector<vector<int>>& matrix, int x, int y)
    {
        return x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] != -200;
    }

    pair<int, int> getNextPos(int x, int y, int direction)
    {
        switch (direction)
        {
        case 0: return {x, y + 1};
        case 1: return {x + 1, y};
        case 2: return {x, y - 1};
        case 3: return {x - 1, y};
            default: return {-1, -1};
        }
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        int direction = 0;

        int x = 0;
        int y = -1;
        int count = 0;
        int total = m * n;
        while (count < total)
        {
            auto next = getNextPos(x, y, direction);
            if (isValid(matrix, next.first, next.second))
            {
                x = next.first;
                y = next.second;
                ans.push_back(matrix[x][y]);
                matrix[x][y] = -200;
                count++;
            }
            else
            {
                direction = getNextDirection(direction);
                // next = getNextPos(x, y, direction);
                // if (!isValid(matrix, next.first, next.second)) { break; }
            }
        }
        return ans;
    }

    virtual void main() override
    {
        vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
        spiralOrder(matrix);
    }
};

#endif //ALGORITHM_SPIRALMATRIX_H