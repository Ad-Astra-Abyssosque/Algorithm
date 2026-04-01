//
// Created by wcx on 2026/3/30.
//

#ifndef ALGORITHM_GENERATEPARENTHESES_H
#define ALGORITHM_GENERATEPARENTHESES_H
#include "../../../Solution.h"
#include <string>

using namespace std;


class GenerateParentheses: public Solution
{
public:
    vector<string> ans;

    vector<string> generateParenthesis(int n) {
        string str;
        work(str, 0, 0, n);
        return ans;
    }

    void work(string& str, int leftParentheses, int rightParentheses, int n)
    {
        if (str.length() == n * 2)
        {
            ans.push_back(str);
            return;
        }

        if (leftParentheses < n)
        {
            str.push_back('(');
            work(str, leftParentheses + 1, rightParentheses, n);
            str.pop_back();
        }


        if (rightParentheses < leftParentheses)
        {
            str.push_back(')');
            work(str, leftParentheses, rightParentheses + 1, n);
            str.pop_back();
        }

    }

    virtual void main() override
    {
        generateParenthesis(3);
        cout << ans.size() << endl;
        for (string& str: ans)
        {
            cout << str << endl;
        }
    }
};


#endif //ALGORITHM_GENERATEPARENTHESES_H