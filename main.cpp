#include <iostream>
#include <memory>

#include "Solution.h"
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


#include "Template/MaxHeap.h"
#include "Template/QuickSort.h"
#include "Template/UnionFind.hpp"

class TestA
{
public:
    TestA()
    {
        p = new int();
        *p = 0xffff;
    }
    ~TestA()
    {
        cout << "~TestA()" << endl;
        delete p;
    }

    int *p;
};

class TestB
{
    TestA a;
public:
    operator TestA()
    {
        cout << "implicit convert" << endl;
        return TestA();
    }
    explicit operator const TestA& () const {
        cout << "explicit convert" << endl;
        return a;
    }
};

const TestA& TestFunc(const TestA& b)
{
    return b;
}

template <typename T>
class Container
{
public:
    Container(T val): data(val) {}
    ~Container() = default;
    void display() const
    {
        std::cout << "Generic Container: " << data <<endl;
    }
private:
    T data;
};

template <>
class Container<int*>
{
public:
    Container(int* val) : data(val) {}
    ~Container() = default;

    void display() const
    {
        cout << "Pointer Container: " << *data << endl;
    }

private:
    int* data;
};


class Base
{
public:
    Base() : base_val(0) {}
    Base(int val): base_val(val) {}

    virtual void printInfo() const
    {
        cout << "Base value = " << base_val << endl;
    }

protected:
    int base_val;
};

class Derived: public Base
{
public:
    Derived() = default;
    Derived(int base, int derived) : Base(base), derived_val(derived) {}

    virtual void printInfo() const
    {
        cout << "Base value = " << base_val << ", Derived value = " << derived_val << endl;
    }

private:
    int derived_val;
    int extra;
};

void printFunc(const Base arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i].printInfo();
    }
}

int main() {
    // auto solution = std::make_shared<LongsetIncreasingSubsequence>();
    // solution->main();
    // cout << sizeof(Base) << " " << sizeof(Derived) << endl;
    // Derived arr[2];
    // arr[0] = Derived(0, 1);
    // arr[1] = Derived(3, 2);
    // printFunc(arr, 2);

    TestB testB;
    const TestA& testA = TestFunc(testB);
    int i = *(testA.p);
    std::cout << i <<std::endl;
    return 0;

    // Container<int> c1(5);
    // c1.display();
    // Container<int*> c2(new int(42));
    // c2.display();
    // return 0;


}


