//
//  virtual_func.cpp
//  practice-cpp
//
//  Created by Tad on 2020/3/11.
//  Copyright © 2020 yangda. All rights reserved.
//

#include <iostream>
#include "virtual_func.hpp"

using namespace std;

class A {
public:
};

A a;

class B {
public:
    // 普通成员函数不占用类对象内存
    void func1(){}
    void func2(){}
};

B b;

class C {
public:
    void func1(){}
    void func2(){}
    virtual void vfunc(){}
};

C c;

class D {
public:
    // 普通成员函数不占用类对象内存
    void func1(){}
    void func2(){}
    // 虚函数、虚函数表(vtbl)，归属于类。
    virtual void vfunc(){}
    virtual void vfunc1(){}
    // 析构函数
    virtual ~D(){}
    // 该类共有3个虚函数，组成该类的虚函数。
private:
    int m_a;
    int m_b;
};

// 对象d有个虚函数表指针(vptr)指向D的函数函数表，归属于类对象。
D d;

class Base {
public:
    virtual void vfunc(){}
};

class Derive : public Base {
public:
    virtual void vfunc(){}
};

int main(int argc, const char * argv[]) {
    cout << "sizeof a: " << sizeof(a) << endl;
    cout << "sizeof b: " << sizeof(b) << endl;
    cout << "sizeof c: " << sizeof(c) << endl;
    // sizeof(d)为16，4个字节为m_a，4个字节为m_b，8个为类对象的虚函数表指针，x86为4个字节。
    cout << "sizeof d: " << sizeof(d) << endl;
    
    // 多态
    Base* base = new Base();
    base->vfunc();
    // 非多态
    Base base1;
    base1.vfunc();
    // 多态
    Base* base2 = &base1;
    base2->vfunc();
    
    Derive derive;
    Base* base3 = &derive;
    base3->vfunc();
    
    Base* base4 = new Derive();
    base4->vfunc();
    
    Derive derive2;
    Base& base5 = derive2;
    base5.vfunc();

    return 0;
}
