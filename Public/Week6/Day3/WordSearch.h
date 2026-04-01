//
// Created by wcx on 2026/3/31.
//

#ifndef ALGORITHM_WORDSEARCH_H
#define ALGORITHM_WORDSEARCH_H
#include "../../../Solution.h"
#include <string>

using namespace std;

class WordSearch: public Solution
{
public:
    int m;
    int n;
    vector<vector<bool>> visited;
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        visited.resize(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (search(board, word, 0, i, j))
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool search(vector<vector<char>>& board, const string& word, int idx, int x, int y)
    {
        if (idx == word.length()) { return true; }
        if (!isValid(x, y) || visited[x][y] || board[x][y] != word[idx]) { return false; }

        visited[x][y] = true;
        bool up = search(board, word, idx + 1, x - 1, y);
        bool down = search(board, word, idx + 1, x + 1, y);
        bool left = search(board, word, idx + 1, x, y - 1);
        bool right = search(board, word, idx + 1, x, y + 1);
        visited[x][y] = false;
        return up || down || left || right;

    }

    bool isValid(int x, int y)
    {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    virtual void main() override
    {
        vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
        exist(board, "ABCCED");
    }
};

#endif //ALGORITHM_WORDSEARCH_H