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
问题一：哪些函数不能实现成虚函数？

虚函数依赖：
1.虚函数能产生地址，存储在vftable当中
2.对象必须存在（vfptr -> vftable ->虚函数地址)

构造函数
1.virtual+构造函数 NO！
2.构造函数中（调用的任何函数，都是静态绑定的）调用虚函数，也不会发生静态绑定
派生类对象构造过程 1.先调用的是基类的构造函数 2.才调用派生类的构造函数

static静态成员方法 NO！ virtual + static

问题二：虚析构函数  析构函数调用的时候，对象是存在的！
什么时候把基类的析构函数必须实现成虚函数？
基类的指针（引用）指向堆上new出来的派生类对象的时候，delete pb（基类的指针），
它调用析构函数的时候，必须发生动态绑定，否则会导致派生类的析构函数无法调用
*/

class Base {
public:
	Base(int data) :ma(data) { cout << "Base()" << endl; }
	// 虚析构函数
	virtual ~Base() { cout << "~Base()" << endl; }
	virtual void show() { cout << "call Base::show()" << endl; }
protected:
	int ma;
};// &Base::~Base  &Base::show
class Derive :public Base {  // &Derive::~Derive  &Derive::show
public:
	Derive(int data) :Base(data), mb(data), ptr(new int(data)) { cout << "Derive()" << endl; }
	// 基类的析构函数是virtual虚函数，那么派生类的析构函数自动成为虚函数
	~Derive() { cout << "~Derive()" << endl; }
private:
	int mb;
	int* ptr;
};


int main() {
	Base* pb = new Derive(10);
	pb->show(); // 动态绑定 pb Base*  *pb
	delete pb;
	/*
	pb->Base  Base::~Base  对于析构函数的调用，就是静态绑定了
	call Base::~Base

	pb->Base  Base::~Base()  对于析构函数的调用，就是动态绑定了
	pb -> Derive  Derive vftable  &Derive::~Derive
	*/

	/*Derive d(10);
	Base* pb = &d;
	pb->show();*/

	return 0;
}