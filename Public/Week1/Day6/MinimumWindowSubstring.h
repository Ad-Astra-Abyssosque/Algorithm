//
// Created by wcx on 2026/2/7.
//

#ifndef ALGORITHM_MINIMUMWINDOWSUBSTRING_H
#define ALGORITHM_MINIMUMWINDOWSUBSTRING_H
#include <iostream>
#include <ostream>
#include <string>
#include <unordered_map>

#include "../../../Solution.h"

class MinimumWindowSubstring: public Solution {
public:
    inline bool isQualified(const std::unordered_map<char, int>& map) {
        for (const auto& it: map) {
            if (it.second < 0) return false;
        }
        return true;
    }

    std::string minWindow(std::string s, std::string t) {
        if (s.length() < t.length()) { return ""; }

        std::unordered_map<char, int> map;
        int charInT[128] = {0};
        for (char c: t) {
            map[c]--;
            charInT[c] = 1;
        }

        int start = 0, end = 0;
        int bestL = 0, bestLen = INT_MAX;
        std::string result;

        while (end < s.length()) {

            // move end
            if (!isQualified(map)) {
                // 如果end所指字符，不曾出现在t中，则不对map操作
                char c = s[end];
                if (charInT[s[end]] != 0) {
                    map[s[end]]++;
                    if (map[s[end]] == 0) {
                        map.erase(s[end]);
                    }
                }
            }
            while (isQualified(map)) {
                int len = end - start + 1;
                if (len < bestLen) { bestLen = len; bestL = start; }
                if (charInT[s[start]] != 0) {
                    map[s[start]]--;
                    if (map[s[start]] == 0) {
                        map.erase(s[start]);
                    }
                }
                start++;
            }
            end++;

        }
        return bestLen == INT_MAX ? "" : s.substr(bestL, bestLen);
    }

    string minWindow2(string s, string t) {
        if (s.length() < t.length()) { return ""; }

        unordered_map<char, int> diff;
        unordered_map<char, bool> stat;
        int diff_count = 0;

        for (int i = 0; i < t.length(); i++) {
            diff[t[i]]--;
            diff[s[i]]++;
            stat[t[i]] = true;
        }

        for (auto& it: stat) {
            if (diff[it.first] < 0) {
                diff_count++;
            }
        }

        int head = 0;
        int tail = t.length() - 1;
        int len = INT_MAX;
        int ans_head = 0;
        int ans_tail = 0;

        while (tail < s.length() || diff_count == 0) {
            // shrink head
            if (diff_count == 0) {
                if (tail - head + 1 < len) {
                    ans_head = head;
                    ans_tail = tail;
                    len = tail - head + 1;
                }

                char head_c = s[head];
                head++;
                if (stat[head_c]) {
                    if (diff[head_c] == 0) {
                        diff_count++;
                    }
                }
                diff[head_c]--;
            }
            // expand tail
            else {
                tail++;
                char tail_c = s[tail];

                if (stat[tail_c]) {
                    if (diff[tail_c] == -1) {
                        diff_count--;
                    }
                }
                diff[tail_c]++;
            }

        }

        return len == INT_MAX ? "" : s.substr(ans_head, len);

    }

    virtual void main() override {
        std::string s = "bbaa";
        std::string t = "aba";
        std::cout << minWindow2(s, t) << std::endl;
    }
};

#endif //ALGORITHM_MINIMUMWINDOWSUBSTRING_H