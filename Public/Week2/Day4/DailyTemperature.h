//
// Created by wcx on 2026/2/13.
//

#ifndef ALGORITHM_DAILYTEMPERATURE_H
#define ALGORITHM_DAILYTEMPERATURE_H

#include <stack>
#include <vector>
using namespace std;

class DailyTemperature
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer = vector<int>(temperatures.size(), 0);
        stack<int> st;
        for (int i = 0; i < temperatures.size(); i++)
        {
            if (st.empty() || temperatures[i] <= temperatures[st.top()])
            {
                st.push(i);
            }
            else
            {
                while (!st.empty() && temperatures[i] > temperatures[st.top()])
                {
                    answer[st.top()] = i - st.top();
                    st.pop();
                }
                st.push(i);
            }
        }
        return answer;
    }
};

#endif //ALGORITHM_DAILYTEMPERATURE_H