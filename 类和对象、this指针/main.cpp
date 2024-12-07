#include <iostream>
using namespace std;

/*
C++ OOP面向对象    OOP编程，this指针
C:  各种各样的函数的定义  Struct
C++:类  =>  实体的抽象类型
实体（属性、行为）  ->  ADT(abstract data type)
 |                       |
对象                <- （实例化） 类 （属性->成员变量  行为->成员方法）

OOP语言的四大特征是什么？
抽象    封装/隐藏    继承    多态

类 -> 商品实体
访问限定符: public公有的 private私有的 protected保护的
*/
const int NAME_LEN = 20;
class CGoods { // => 商品的抽象数据类型
public:  // 给外部提供公有的方法，来访问私有的属性
	// 做商品数据初始化用的
	void init(const char* name, double price, int amount);
	// 打印商品信息
	void show();
	// 给成员变量提供一个getXXX或setXXX的方法 类体内实现的方法，自动化处理成inline函数
	void setName(char* name) { strcpy(_name, name); }
	void setPrice(double price) { _price = price; }
	void setAmount(int amount) { _amount = amount; }

	const char* getName() { return _name; }
	double getPrice() { return _price; }
	int getAmount() { return _amount; }
private: // 属性一般是私有的成员变量
	char _name[NAME_LEN];
	double _price;
	int _amount;
};
inline void CGoods::init(const char* name, double price, int amount) {
	strcpy(_name, name);
	_price = price;
	_amount = amount;
}
void CGoods::show() {
	cout << "name:" << _name << "\n";
	cout << "price:" << _price << "\n";
	cout << "amount:" << _amount << endl;
}
int main() {
	/*
	CGoods可以定义无数的对象，每一个对象都有自己的成员变量
	但是他们共享一套成员方法

	show() => 怎么知道处理哪个对象的信息？
	init(name, price, amount) => 怎么知道把信息初始化给哪一个对象的呢？

	类的成员方法一经编译，所有的方法参数，都会加一个this指针，接收调用该方法的对象的地址
	*/
	// cl 文件名.cpp /dlreportSingleClassLayout成员方法
	// 对象内存大小 => 只和成员变量有关
	CGoods good1; // 类实例化了一个对象

	// init(&good1, "C", 9, 1024);
	good1.init("C", 9, 1024);
	// show(&good1)
	good1.show();

	good1.setPrice(10.0);
	good1.setAmount(2048);
	good1.show();

	CGoods good2; // 类实例化了一个对象
	good2.init("C++", 10.0, 4096);
	good2.show();

	return 0;
}