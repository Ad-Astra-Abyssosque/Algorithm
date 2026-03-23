//
// Created by wcx on 2026/3/5.
//

#ifndef ALGORITHM_NUMBEROFISLANDS_H
#define ALGORITHM_NUMBEROFISLANDS_H

#include <vector>
#include <stack>
#include <unordered_map>

#include "../../../Solution.h"

class NumberOfIsland: Solution
{
public:
    void findFirst(std::pair<int, int>& firstLand, std::vector<std::vector<char>>& grid)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                visited[i * n + j] = true;
                if (grid[i][j] == '1')
                {
                    firstLand = {i, j};
                    return;
                }
            }
        }
    }

    int numIslands(std::vector<std::vector<char>>& grid) {

        m = grid.size();    // 行数
        n = grid[0].size(); // 列数
        visited = std::vector<bool>(m * n, false);

        // 横向找到第一块陆地
        std::pair<int, int> firstLand = {-1, -1};
        findFirst(firstLand, grid);
        if (firstLand.first == -1) return 0;
        // 将相邻的陆地加入栈
        lands.push(firstLand);
        while (!lands.empty() || !edges.empty())
        {
            // 遍历所有相邻的陆地，并将周围的海洋加入edges中
            expand(lands, grid, false);
            island++;
            // 遍历edges中所有相邻的海洋单元格，并将遇到的陆地加入lands
            // 但需要警惕一种情况：一块海洋的左方和下方都是陆地。
            // 但这两个陆地并不联通，都加入lands中会导致他们被认为联通
            // 因此需要在找到一块陆地后就返回

            // 但这样又会带来问题：该块海洋被标记为visited，此后不会再访问它，
            // 但如果其相邻的另一块陆地不能被其他海洋访问到（例如在上一个例子中，下方陆地被visit，直接返回，左方陆地未被访问
            // 左方的陆地就再也不会被访问，从而漏统计
            // 解决方法是再次将该海洋标记为 unvisited
            expand(edges, grid, true);
        }
        return island;

    }

    bool isValid(int x, int y)
    {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    bool work(int x, int y, std::vector<std::vector<char>>& grid)
    {
        if (!isValid(x, y) || visited[x * n + y]) return false;
        visited[x * n + y] = true;
        if (grid[x][y] == '1')
        {
            lands.push({x, y});
            return true;
        }
        else
        {
            edges.push({x, y});
            return false;
        }
    }

    void expand(std::stack<std::pair<int, int>>& objects, std::vector<std::vector<char>>& grid, bool returnImmediately)
    {
        while (!objects.empty())
        {
            auto object = objects.top();
            objects.pop();
            visited[object.first * n + object.second] = true;
            // up
            if (work(object.first - 1, object.second, grid) && returnImmediately)
            {
                visited[object.first * n + object.second] = false;
                return;
            }
            // down
            if (work(object.first + 1, object.second, grid) && returnImmediately)
            {
                visited[object.first * n + object.second] = false;
                return;
            }
            // left
            if (work(object.first, object.second - 1, grid) && returnImmediately)
            {
                visited[object.first * n + object.second] = false;
                return;
            }
            // right
            if (work(object.first, object.second + 1, grid) && returnImmediately)
            {
                visited[object.first * n + object.second] = false;
                return;
            }
        }
    }

    int m = 0;
    int n = 0;
    int island = 0;
    std::stack<std::pair<int, int>> lands;
    std::stack<std::pair<int, int>> edges;
    std::vector<bool> visited;


    virtual void main() override
    {
        // std::vector<std::vector<char>> grid = {{'1'}};
        std::vector<std::vector<char>> grid = {
            {'1','0','1','1','1'},
            {'1','0','1','0','1'},
            {'1','1','1','0','1'}
        };
        std::cout << numIslands(grid) << std::endl;
    }
};

#endif //ALGORITHM_NUMBEROFISLANDS_H