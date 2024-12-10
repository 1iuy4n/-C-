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
1.继承的本质和原理
继承的本质：a.代码的复用 b.
类和类之间的关系：
组合：a part of……一部分的关系
继承：a kind of……一种的关系

继承方式    基类的访问限定    派生类的访问限定    （main)外部的访问限定
public
            public            public               Y
			protected         protected            N
			private           不可见的             N
protected（基类的成员的访问限定，在派生类里面是不可能超过继承方式的）
			public            protected            N
			protected         protected            N
			private           不可见的             N
private
			public            private              N
			protected         private              N
			private           不可见的             N

总结：
1.外部只能访问对象public的成员，protected和private的成员无法直接访问
2.在继承结构中，派生类从基类可以继承过来private的成员，但是派生类却无法直接访问
3.protected和private的区别？在基类中定义的成员，想被派生类访问，但是不想被外部访问，
那么在基类中，把相关成员定义成protected保护的；如果派生类和外部都不打算访问，
那么在基类中，就把相关成员定义成private私有的。

默认的继承方式是什么？
要看派生类使用class定义的，还是struct定义的
class定义派生类，默认继承方式就是private私有的
struct定义派生类，默认继承方式就是public公有的
*/
class A {
public:
	A(int _ma, int _mb, int _mc) :ma(_ma), mb(_mb), mc(_mc) {}
	int ma;
protected:
	int mb;
private:
	int mc; // 只有自己或者友元能访问私有的成员
	friend void testFriend(A& src);
};
// 继承 A 基类/父类    B 派生类/子类
class B : private A {
public:
	B(int _ma, int _mb, int _mc, int _md, int _me, int _mf):
		A(_ma, _mb, _mc), 
		md(_md), me(_me), 
		mf(_mf){}
	int md;
protected:
	int me;
private:
	int mf;
};
class C : public B {
	// 在C里面，请问ma的访问限定是什么？不可见的，但是能继承来
};

void testFriend(A& src) {
	cout << src.mc << endl;
}
int main() {
	A a(0, 1, 2);
	testFriend(a);

	B b(0, 1, -2, 3, 4, 5);
	// testFriend(b);
	cout << b.md << endl;
	return 0;
}