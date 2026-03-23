//
// Created by wcx on 2026/2/7.
//

#ifndef ALGORITHM_PERMUTATIONINSTRING_H
#define ALGORITHM_PERMUTATIONINSTRING_H
#include <string>
#include <unordered_map>

class PermutationInString {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        std::unordered_map<char, int> map;
        if (s1.length() > s2.length()) { return false; }
        // init map
        for (char c: s1) {
            map[c]--;
        }
        // init window
        int start = 0, end = 0;
        while (end < s1.length()) {
            map[s2[end]]++;
            if (map[s2[end]] == 0) {
                map.erase(s2[end]);
            }
            end++;
        }

        if (map.empty()) {
            return true;
        }
        while (end < s2.length()) {
            map[s2[start]]--;
            if (map[s2[start]] == 0) {
                map.erase(s2[start]);
            }
            map[s2[end]]++;
            if (map[s2[end]] == 0) {
                map.erase(s2[end]);
            }

            start++;
            end++;
            if (map.empty()) {
                return true;
            }

        }
        return false;
    }
};

#endif //ALGORITHM_PERMUTATIONINSTRING_H