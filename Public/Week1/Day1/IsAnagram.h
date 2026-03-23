//
// Created by wcx on 2026/2/1.
//

#ifndef ALGORITHM_ISANAGRAM_H
#define ALGORITHM_ISANAGRAM_H

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class IsAnagram {
public:
    // Better Solution
    bool isAnagram_Better(string s, string t) {
        if (s.length() != t.length() || s == t) {
            return false;
        }
        vector<int> table(26, 0);
        for (auto& ch: s) {
            table[ch - 'a']++;
        }
        for (auto& ch: t) {
            table[ch - 'a']--;
            if (table[ch - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }


    // My Solution
    bool isAnagram(std::string s, std::string t) {
        if (s != t) {
            auto map_s = statChar(s);
            auto map_t = statChar(t);
            return unordered_map_equal(map_s, map_t);
        }
        return false;
    }

    std::unordered_map<char, int> statChar(const std::string& str) {
        std::unordered_map<char, int> result;
        for (auto i : str) {
            if (result.contains(i)) {
                result[i] += 1;
            }
            else {
                result[i] = 1;
            }
        }
        return result;
    }

    template<typename K, typename V>
    bool unordered_map_equal(const std::unordered_map<K, V>& map1,
                         const std::unordered_map<K, V>& map2) {
        // 先比较大小
        if (map1.size() != map2.size()) {
            return false;
        }

        // 遍历第一个map，在第二个map中查找每个键值对
        for (const auto& pair : map1) {
            auto it = map2.find(pair.first);
            if (it == map2.end() || it->second != pair.second) {
                return false;
            }
        }
        return true;
    }

};

#endif //ALGORITHM_ISANAGRAM_H