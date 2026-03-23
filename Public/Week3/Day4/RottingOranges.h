//
// Created by wcx on 2026/3/6.
//

#ifndef ALGORITHM_ROTTINGORANGES_H
#define ALGORITHM_ROTTINGORANGES_H

#include <queue>
#include <vector>
#include <stack>

class RottingOranges
{
    int orangesRotting(std::vector<std::vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();
        int minute = -1;
        bool empty = true;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    rottedOranges.push({i, j});
                    empty = false;
                }
                else if (grid[i][j] ==  1)
                {
                    freshCount++;
                    empty = false;
                }
            }
        }
        if (empty) return 0;

        while (!rottedOranges.empty())
        {
            int len = rottedOranges.size();
            for (int i = 0; i < len; i++)
            {
                auto rotted = rottedOranges.front();
                rottedOranges.pop();
                grid[rotted.first][rotted.second] = 0;
                rot(rotted.first - 1, rotted.second, grid);
                rot(rotted.first + 1, rotted.second, grid);
                rot(rotted.first, rotted.second - 1, grid);
                rot(rotted.first, rotted.second + 1, grid);
            }
            minute++;
        }

        return freshCount ? -1 : minute;
    }

    bool isValid(int x, int y)
    {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    void rot(int x, int y, std::vector<std::vector<int>>& grid)
    {
        if (!isValid(x, y)) return;

        if (grid[x][y] == 1)
        {
            grid[x][y] = 2;
            rottedOranges.push({x, y});
            freshCount--;
        }
    }

    int m = 0;
    int n = 0;
    int freshCount = 0;
    std::queue<std::pair<int, int>> rottedOranges;
};

#endif //ALGORITHM_ROTTINGORANGES_H