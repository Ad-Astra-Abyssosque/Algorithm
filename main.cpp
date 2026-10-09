#include <iostream>
#include <memory>
#include <queue>

#include "Solution.h"
#include "Public/preorder_midorder.h"
#include "Public/Week1/Day1/TwoSum.h"
#include "Public/Week1/Day2/SubArraySumEqualsK.h"
#include "Public/Week1/Day3/MoveZeros.h"
#include "Public/Week1/Day4/ThreeSum.h"
#include "Public/Week1/Day4/TrappingRainWater.h"
#include "Public/Week1/Day5/LongestSubstringWithoutRepeatingChar.h"
#include "Public/Week1/Day5/MinSizeSubarraySum.h"
#include "Public/Week1/Day5/FindAllAnagramsInString.h"
#include "Public/Week1/Day6/MinimumWindowSubstring.h"
#include "Public/Week1/Day7/FindFirstAndLast.h"

#include "Public/Week2/Day2/LinkedListCycle.h"
#include "Public/Week2/Day5/FindKthLargest.h"
#include "Public/Week2/Day5/TopKFrequentEle.h"
#include "Public/Week2/Day6/NonOverlappingIntervals.h"
#include "Public/Week2/Day7/JumpGame.h"

#include "Public/Week3/Day2/ValidateBinarySearchTree.h"
#include "Public/Week3/Day3/FlatternBinaryTreeToLinkedList.h"
#include "Public/Week3/Day4/NumberOfIslands.h"
#include "Public/Week3/Day5/CourseSchedule.h"

#include "Public/Week4/Day5/LongsetIncreasingSubsequence.h"

#include "Public/Week5/Day1/Permutations.h"
#include "Public/Week5/Day1/Permutations_Better.h"
#include "Public/Week5/Day2/Subsets.h"
#include "Public/Week5/Day2/Subsets_Binary.h"
#include "Public/Week5/Day2/Subsets_Recursion.h"
#include "Public/Week5/Day4/LRUCache.h"
#include "Public/Week5/Day6/EditDistance.h"

#include "Public/Week6/Day1/CombinationSum.h"
#include "Public/Week6/Day2/GenerateParentheses.h"
#include "Public/Week6/Day3/WordSearch.h"
#include "Public/Week6/Day4/HouseRobber2.h"
#include "Public/Week6/Day5/SpiralMatrix.h"

#include "Public/Week7/Day1/DecodeString.h"

#include "Template/MaxHeap.h"
#include "Template/QuickSort.h"
#include "Template/UnionFind.hpp"
#include "Template/Sort/InsertSort.h"
#include "Template/Sort/BubbleSort.h"

#include "Public/Tencent/TencentOnlineTest.h"
#include "Public/Week7/Day2/ParsePalindrome.h"

class base
{
public:
    int a = 1;
    virtual void print(int n = 3)
    {
        cout << a+n;
    }
};
class derive : public base
{
public:
    int b = 2;
    virtual void print(int m)
    {
        cout << b+m;
    }
};

class ABC {
public:
    ABC(int x) { cout << x << endl; }
};


int main() {
//    std::string s1 = "short";            // 可能用 SSO
//    std::string s2 = "this is a very long string that exceeds SSO threshold";
//
//    std::cout << "s1 capacity: " << s1.capacity() << std::endl; // 通常 15
//    std::cout << "s2 capacity: " << sizeof(s2) << std::endl; // >15


    // std::cout << sizeof(base) << " " << sizeof(derive) << endl;
    // // derive* b = new derive[10];
    // // b[7].print();
    // ABC* p = new ABC[2]{ {1}, {2} };
    // base* b = new derive;
    // b->print();
    // std::vector<int> a;
    //
    // std::find(a.begin(), a.end(), 0);
    //
    // auto solution = std::make_shared<MinimumWindowSubstring>();
    // solution->main();
    // queue<int> que;
    // que.front();
    //
    // vector<int> a = {2, 2, 3, 4, 4};
    // vector<int> b = {1, 2, 3, 5};
    // int k = 9;
    // int i = a.size() - 1;
    // int j = b.size() - 1;
    // int ans = 0;
    // while (true)
    // {
    //     if (i < 0) { ans = b[j - k + 1]; break;}
    //     if (j < 0) { ans = a[i - k + 1]; break; }
    //     if (k == 0) { ans = max(a[i], b[j]); break; }
    //     if (a[i] < b[j])
    //     {
    //         j--;
    //     }
    //     else
    //     {
    //         i--;
    //     }
    //     k--;
    // }
    // cout << ans << endl;

    // int arr[3] = {1, 2, 3};
    // cout << arr << ", " << &arr << endl;
    //
    // int* num = new int(5);
    // cout << *num << ", " << num << endl;
    // delete num;

    // cout << sizeof(Base) << " " << sizeof(Derived) << endl;
    // Derived arr[2];
    // arr[0] = Derived(0, 1);
    // arr[1] = Derived(3, 2);
    // printFunc(arr, 2);

    // Q4
    // TestB testB;
    // const TestA& testA = TestFunc(testB);
    // int i = *(testA.p);
    // std::cout << i <<std::endl;

    // Q5
    // char p1[] = "abcde";
    // const char* p2 = "abcdc";
    // const char* p3 = p2 + 3;
    // int size1 = (int*)p3 - (int*)p2;
    // cout << size1 << endl;
    // cout << sizeof(Test) << endl;
    // cout << sizeof(Test1) << endl;
    //
    // cout << "======" << endl;
    // A a(22, 33);
    // int* arr = (int*)&a;
    // cout << arr[2] << endl;
    //
    // // Q8
    // cout << "======" << endl;
    // Container<int> c1(5);
    // c1.display();
    // Container<int*> c2(new int(42));
    // c2.display();

    // Q9
    // cout << "======" << endl;
    // vector<TestC> Context;
    // TestC a1(1, 2);
    // Context.push_back(a1);
    // TestC& p = Context[0];
    // for (int i = 0; i < 10; i++)
    // {
    //     Context.push_back(p);
    // }
    //
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << Context[i].a << ", " << Context[i].b << endl;
    // }

    // Q10
    // Player* player = new Player(0, 0);
    // Enemy* enemy1 = new Enemy(3, 4);
    // Enemy* enemy2 = new Enemy(10, 10);
    //
    // if (player->isColliding(enemy1)) {
    //     player->onCollision();
    //     enemy1->onCollision();
    // }
    //
    // if (player->isColliding(enemy2)) {
    //     player->onCollision();
    //     enemy2->onCollision();
    // }
    //
    // delete player;
    // delete enemy1;
    // delete enemy2;

    string s;
    cin >> s;

    string res;

    for (int i = 0; i < (int)s.size(); ) {
        int j = i;

        while (j < (int)s.size() && s[j] == s[i]) {
            ++j;
        }

        res += s[i];

        int cnt = j - i;
        if (cnt > 1) {
            res += to_string(cnt);
        }

        i = j;
    }

    cout << res << '\n';



}

void func(int x = 1)
{
    cout << x << endl;
}
