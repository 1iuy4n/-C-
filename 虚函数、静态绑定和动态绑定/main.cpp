#include <iostream>
#include <typeinfo>
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
虚函数，静态绑定和动态绑定

覆盖：
基类和派生类的方法，返回值、虚函数名以及参数列表相同，而且基类的方法是虚函数，
那么派生类的方法就自动处理成虚函数，它们之间成为覆盖关系

一个类添加了虚函数，对这个类有什么影响？
总结一：
如果类里面定义了虚函数，那么编译阶段，编译器给这个类类型产生一个唯一的vftable虚函数表，
虚函数表中主要存储的内容就是RTTI指针和虚函数的地址。
当程序运行时，每一张虚函数表都会加载到内存的.rodata区

总结二：
一个类里面定义了虚函数，那么这个类定义的对象，
其运行时，内存开始部分，多存储一个vfptr虚函数指针，
指向相应类型的虚函数表vftable。
一个类型定义的n个对象，它们的vfptr指向的都是同一张虚函数表。

总结三：
一个类里面虚函数的个数，不影响对象内存大小（vfptr），影响的是虚函数表的大小
*/
class Base {
public:
	Base(int data=10):ma(data){}
	// 虚函数
	virtual void show() { cout << "Base::show()" << endl; }
	// 虚函数
	virtual void show(int) { cout << "Base::show(int)" << endl; }
protected:
	int ma;
};
class Derive : public Base {
public:
	Derive(int data=20):Base(data), mb(data){}
	/*
	总结四：
	如果派生类中的方法，和基类继承来的某个方法，返回值、函数名、参数列表都相同，
	而且基类的方法是virtual函数，那么派生类的这个方法，自动处理成虚函数
	重写 《=》覆盖
	覆盖：虚函数表中虚函数地址的覆盖
	*/
	void show() { cout << "Derive::show()" << endl; }
private:
	int mb;
};
class sizeTest {
	int a;
	int* b;
};
int main() {

	Derive d(50);
	Base* pb = &d;

	/*
	pb->Base Base::show 如果发现show是普通函数，就进行静态绑定
	                                             call Base::show()
	pb->Base Base::show 如果发现show是虚函数，就进行动态绑定了
	mov eax, dword ptr[pb]
	mov ecx, dword ptr[eax]
	call ecx(虚函数的地址)  动态（运行时期）的绑定（函数的调用）
	*/
	pb->show();   // 静态（编译时期）的绑定（函数的调用）call        Base::show (07FF7257A13F7h)
	
	/*
	Base::show(int)  是一个虚函数，此时就得动态绑定了
	mov eax, dword ptr[pb]
	mov ecx, dword ptr[eax]
	call ecx(虚函数的地址)  动态（运行时期）的绑定（函数的调用）
	*/
	pb->show(10); // 静态绑定 call        Base::show (07FF7A28710DCh)

	cout << sizeof(Base) << endl;   // 4 16
	cout << sizeof(Derive) << endl; // 8 24
	/*
	需要注意的是这里sizeof答应出来的类的大小和/d1reportSingleClassLayout的大小不一样
	sizeof打印的Base和Derive的大小分别是 16 和 24
	/d1reportSingleClassLayout中显示类的结构是这样的，显示的大小分别是 8 和 16：
	class Base      size(8):
		+---
 0      | {vfptr}
 4      | ma
		+---

		class Derive    size(12):
		+---
 0      | +--- (base class Base)
 0      | | {vfptr}
 4      | | ma
		| +---
 8      | mb
		+---
	之所以数值对不上是因为sizeof考虑了填充字节，
	根据下面sizeTest的测试，sizeof打印出来的大小是16，而d1reportSingleClassLayout中的结构如下：
	class sizeTest  size(8):
		+---
 0      | a
 4      | b
		+---
	*/
	cout << sizeof(sizeTest) << endl; // 16
	//Base b(50);
	//cout << sizeof(b) << endl;

	cout << typeid(pb).name() << endl;  // class Base*
	/*
	pb的类型：Base->没有虚函数
	如果Base没有虚函数，*pb识别的就是编译时期的类型  *pb <=> Base类型
	如果Base有虚函数，*pb识别的就是运行时期的类型  RTTI类型
	pb->d(vfptr)->Derive vftable class Derive
	*/
	cout << typeid(*pb).name() << endl; // class Base
	/*
	Base的两个show函数都是普通的函数
	Base::show()
	Base::show(int)
	4
	8
	class Base * __ptr64
	class Base
	*/

	/*
	给Base的两个show方法定义成virtual虚函数了
	Derive::show()
	Base::show(int)
	16
	24
	class Base * __ptr64
	class Derive
	*/

	return 0;
}