//
// Created by wcx on 2026/4/6.
//

#ifndef ALGORITHM_TRIE_H
#define ALGORITHM_TRIE_H
#include "../../../Solution.h"
#include <string>

using namespace std;



class Trie: Solution {
public:
    struct TrieNode
    {
        bool isWord = false;
        char letter;
        TrieNode* child[26] = {nullptr};

        TrieNode() = default;
        TrieNode(bool isWord_, char letter_): isWord(isWord_), letter(letter_) {}
    };

    TrieNode* root;

    Trie() {
        root = new TrieNode;
    }

    void insert(string word) {
        TrieNode* cur = root;
        for (const char& c: word)
        {
            int index = c - 'a';
            if (cur->child[index] == nullptr)
            {
                cur->child[index] = new TrieNode(false, c);
            }
            cur = cur->child[index];
        }
        cur->isWord = true;
    }

    bool search(string word) {
        TrieNode* cur = root;
        for (const char& c: word)
        {
            int index = c - 'a';
            if (cur->child[index] != nullptr)
            {
                cur = cur->child[index];
            }
            else
            {
                return false;
            }
        }
        return cur->isWord;
    }

    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (const char& c: prefix)
        {
            int index = c - 'a';
            if (cur->child[index] != nullptr)
            {
                cur = cur->child[index];
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

#endif //ALGORITHM_TRIE_H