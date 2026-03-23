//
// Created by wcx on 2026/2/6.
//

#ifndef ALGORITHM_FINDALLANAGRAMSINSTRING_H
#define ALGORITHM_FINDALLANAGRAMSINSTRING_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "../../../Solution.h"

class FindAllAnagramsInString: public Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        std::vector<int> result;
        std::unordered_map<char, int> map;
        if (p.length() > s.length()) { return result; }
        // init map
        for (char c: p) {
            map[c]--;
        }
        // init window
        int start = 0, end = 0;
        while (end < p.length()) {
            map[s[end]]++;
            if (map[s[end]] == 0) {
                map.erase(s[end]);
            }
            end++;
        }

        if (map.empty()) {
            result.push_back(start);
        }
        while (end < s.length()) {
            map[s[start]]--;
            if (map[s[start]] == 0) {
                map.erase(s[start]);
            }
            map[s[end]]++;
            if (map[s[end]] == 0) {
                map.erase(s[end]);
            }

            start++;
            end++;
            if (map.empty()) {
                result.push_back(start);
            }

        }
        return result;
    }

    virtual void main() override {
        auto res = findAnagrams("bb", "aa");
        for (auto it: res) {
            std::cout << it << std::endl;
        }
    }
};

#endif //ALGORITHM_FINDALLANAGRAMSINSTRING_H