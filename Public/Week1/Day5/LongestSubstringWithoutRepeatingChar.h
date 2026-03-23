//
// Created by wcx on 2026/2/6.
//

#ifndef ALGORITHM_LONGESTSUBSTRINGWITHOUTREPEATINGCHAR_H
#define ALGORITHM_LONGESTSUBSTRINGWITHOUTREPEATINGCHAR_H

#include <iostream>
#include <ostream>
#include <string>

#include "../../../Solution.h"

class LongestSubstringWithoutRepeatingChar: public Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int table[128] = {0};
        int windowLength = 0;
        int result = 0;
        int start = 0, end = 0;
        while (start < s.length() && end < s.length()) {
            char c = s[end];
            if (table[c] == 0) {
                table[c] = 1;
                windowLength++;
                result = std::max(result, windowLength);
                end++;
            }
            else {
                windowLength--;
                table[s[start]] = 0;
                start++;
                //end = start;
            }
        }
        return result;
    }

    virtual void main() override {
        std::cout << lengthOfLongestSubstring("pwwkew") << std::endl;
    }
};


#endif //ALGORITHM_LONGESTSUBSTRINGWITHOUTREPEATINGCHAR_H