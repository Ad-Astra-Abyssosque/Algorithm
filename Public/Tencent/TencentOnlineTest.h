//
// Created by wcx on 2026/3/24.
//

#ifndef ALGORITHM_TENCENTONLINETEST_H
#define ALGORITHM_TENCENTONLINETEST_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

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


#pragma pack(push, 8)
struct Test {
    char i[11];
};

struct Test1 {
    short s1;
    Test i1;
};
#pragma pack(pop)


struct A {
    int data[2];
    A(int x, int y): data{x, y} {}
    virtual void f() {}
};

class TestC
{
public:
    TestC(int a1, int b1)
    {
        a = a1;
        b = b1;
    }

    int a;
    int b;
};

class GameObject {
protected:
    int x, y;      // 物体坐标
    int radius;    // 碰撞半径

public:
    GameObject(int posX, int posY, int r) : x(posX), y(posY), radius(r) {}

    bool isColliding(GameObject* other) {
        int dx = x - other->x;
        int dy = y - other->y;
        int distance = dx * dx + dy * dy;

        int sumRadius = radius + other->radius;
        return distance <= sumRadius * sumRadius;
    }

    virtual void onCollision() = 0;
};

class Player : public GameObject {
public:
    Player(int posX, int posY) : GameObject(posX, posY, 5) {}

    void onCollision() {
        cout << "Player hit at (" << x << ", " << y << ")" << endl;
    }
};

class Enemy : public GameObject {
public:
    Enemy(int posX, int posY) : GameObject(posX, posY, 3) {}

    void onCollision() {
        cout << "Enemy destroyed at (" << x << ", " << y << ")" << endl;
    }
};


#endif //ALGORITHM_TENCENTONLINETEST_H