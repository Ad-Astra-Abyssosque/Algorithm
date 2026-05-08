//
// Created by wcx on 2026/4/16.
//

#ifndef ALGORITHM_PREORDER_MIDORDER_H
#define ALGORITHM_PREORDER_MIDORDER_H
#include "../Solution.h"
#include <algorithm>


using namespace std;

class PreorderMidorder: Solution
{
public:
    void work(vector<char>& preorder, vector<char>& midorder,
        int preStart, int preEnd, int midStart, int midEnd, vector<char>& res)
    {
        if (preStart > preEnd || midStart > midEnd)
        {
            return;
        }

        char start = preorder[preStart];

        auto root = std::find(midorder.begin(), midorder.end(), start);
        int rootIndex = root - midorder.begin();
        int leftSize = root - (midorder.begin() + midStart);

        work(preorder, midorder, preStart + 1, preStart + leftSize,
            midStart, rootIndex - 1, res);

        work(preorder, midorder, preStart + leftSize + 1, preEnd,
            rootIndex + 1, midEnd, res);

        res.push_back(start);
    }

    void main() override
    {
        vector<char> preorder = {'A', 'B', 'D', 'E', 'C', 'F', 'G'};
        vector<char> midorder = {'D', 'B', 'E', 'A', 'F', 'G', 'C'};
        vector<char> res;
        work(preorder, midorder,
            0, preorder.size() - 1,
            0, midorder.size() - 1, res);
        for (char& c: res)
        {
            cout << c << " ";
        }
        cout << endl;
    }
};


#endif //ALGORITHM_PREORDER_MIDORDER_H