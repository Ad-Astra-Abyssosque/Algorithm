//
// Created by wcx on 2026/3/6.
//

#ifndef ALGORITHM_MATRIX01_H
#define ALGORITHM_MATRIX01_H

#include <memory>
#include <queue>
#include <vector>

using namespace std;

class Matrix01
{
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        // init result matrix
        result = vector<vector<int>>(m, vector<int>(n, 0));


        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    zeros.emplace(i, j);
                }
            }
        }

        while (!zeros.empty())
        {
            int len = zeros.size();
            for (int i = 0; i < len; i++)
            {
                auto zero = zeros.front();
                zeros.pop();
                work(zero.first - 1, zero.second, mat);
                work(zero.first + 1, zero.second, mat);
                work(zero.first, zero.second - 1, mat);
                work(zero.first, zero.second + 1, mat);
            }
            distance++;
        }
        return result;

    }

    bool isValid(int x, int y)
    {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    void work(int x, int y, std::vector<std::vector<int>>& grid)
    {
        if (!isValid(x, y)) return;

        if (grid[x][y] == 1)
        {
            grid[x][y] = 0;
            zeros.emplace(x, y);
            result[x][y] = distance;
        }
    }

    int m = 0;
    int n = 0;
    int distance = 1;
    vector<vector<int>> result;
    std::queue<std::pair<int, int>> zeros;
};

#endif //ALGORITHM_MATRIX01_H