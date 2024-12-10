#include <iostream>
using namespace std;

/*
1.继承的本质和原理
2.派生类的构造过程
3.重载、覆盖、隐藏
4.静态绑定和动态绑定
5.多态 vfptr和vftable
6.抽象类的设计原理
7.多重继承以及问题
8.虚基类 vbptr和vbtable
9.RTTI
10.C++四种类型强转
11.继承多态常见笔试面试题分享
*/

/*
派生类怎么初始化从基类继承来的成员变量呢？
1.派生类从基类可以继承来所有的成员（成员和方法），除构造函数和析构函数
派生类怎么初始化从基类继承来的成员变量呢？
解答：调用基类相应的构造函数来初始化

派生类的构造函数和析构函数，负责初始化和清理派生类部分
派生类从基类继承来的成员的初始化和清理是有谁负责呢？是由基类的构造和析构函数来负责

派生类对象构造和析构的过程是：
1.派生类调用基类的构造函数，初始化从基类继承来的成员
2.调用派生类自己的构造函数，初始化派生类自己特有的成员
……派生类对象的作用域到期了
3.调用派生类的析构函数，释放派生类成员可能占用的外部资源（堆内存，文件）
4.调用基类的析构函数，释放派生类内存中，从基类继承来的成员可能占用的外部资源（堆内存，文件）
*/

class Base {
public:
	Base(int data = 10) :ma(data) { cout << "Base()" << endl; }
	~Base() { cout << "~Base()" << endl; }
protected:
	int ma;
};

class Derive : public Base {
public:
	// “Derive”: 非法的成员初始化:“ma”不是基或成员
	Derive(int data = 10) :Base(data), mb(data) { cout << "Derive()" << endl; }
	~Derive() { cout << "~Derive()" << endl; }
protected:
	int mb;
};
int main() {
	Derive d(20);

	return 0;
}