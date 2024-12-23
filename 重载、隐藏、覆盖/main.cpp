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
重载、隐藏、覆盖
1.重载关系
  一组函数要重载，必须处在同一个作用域当中；而且函数名字相同，参数列表不同

2.隐藏（作用域的隐藏）的关系
  在继承结构当中，派生类的同名成员，把基类的同名成员给隐藏调用了

=========================================================================
1.把继承结构，也说成从上（基类）到下（派生类）的结构
2.
基类对象 -> 派生类对象
派生类对象 -> 基类对象

基类指针（引用） -> 派生类对象
派生类指针（引用） -> 基类对象

总结： 在继承机构中进行上下的类型转换，默认只支持从下到上的类型的转换 OK
*/

class Base {
public:
	Base(int data=10):ma(data){}
	void show() { cout << "Base::show()" << endl; }         // #1
	void show(int) { cout << "Base::show(int)" << endl; }   // #2
private:
	int ma;
};
class Derive : public Base {
public:
	Derive(int data=20):Base(data), mb(data){}
	void show() { cout << "Derive::show()" << endl; }       // #3
private:
	int mb;

};

int main() {

	Base b(10);
	Derive d(20);

	// 基类对象b <- 派生类对象d         类型从下到上的转换    Y
	b = d;

	// 派生类对象d <- 基类对象b         类型从上到下的转换    N
	// d = b;
	// 基类指针（引用）<- 派生类对象    类型从下到上的转换    Y
	Base *pb = &d;
	// ((Derive*)pb)->show();
	pb->show(10);

	// 派生类指针（引用） <- 基类对象   类型从上到下的转换    N
	Derive* pd = (Derive*) & b; // 不安全，涉及了内存的非法访问！
	pd->show();

#if 0
	Derive d;
	d.show();
	d.Base::show();
	d.Base::show(10); 
	// “Derive::show”: 函数不接受 1 个参数
	// d.show(10); // // 优先找的是派生类自己作用域的show名字成员；没有的话，才去基类里面找
#endif
	return 0;
}