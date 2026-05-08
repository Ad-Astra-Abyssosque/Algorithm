//
// Created by wcx on 2026/4/30.
//

#ifndef ALGORITHM_ABLIST_H
#define ALGORITHM_ABLIST_H

#include <set>

using namespace std;

/**
* 实现⼀个数据结构
* 1.可以插入两个数字 [a,b] 要求不能和其他的段有重叠｡有重叠则插入失败｡
* 2.可以按照下标删除⼀个段
 */
class ABList
{
    struct Element
    {
        int a;
        int b;
        Element(int a_, int b_): a(a_), b(b_) {}
        bool operator<(const Element& other) const
        {
            if (a != other.a) return a < other.a;
            return b < other.b;
        }
    };

    set<Element> data;

public:
    bool insert(int a, int b)
    {
        Element ele(a, b);
        auto pos = data.lower_bound(ele);
        if (pos != data.begin())
        {
            auto pre = std::prev(pos);
            if (a <= pre->b) { return false;}
        }
        if (pos != data.end() && b >= pos->a)
        {
            return false;
        }
        data.insert(ele);
        return true;

    }

    bool del(int index)
    {
        auto it = data.begin();
        for (int i = 0; i < index && it != data.end(); i++, it++)
        {

        }
        if (it != data.end())
        {
            data.erase(it);
            return true;
        }
        return false;
    }
};

#endif //ALGORITHM_ABLIST_H