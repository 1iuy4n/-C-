#include <iostream>

using namespace std;

/*
类的各种成员 - 成员方法/变量
普通的成员方法 => 编译器会添加一个this形参变量
1.属于类的作用域
2.调用该方法时，需要依赖一个对象（常对象是无法调用的 实参 : const CGoods*    CGoods *this）
3.可以任意访问对象的私有成员变量    protected继承    public    private

static静态成员方法 => 不会生成this形参
1.属于类的作用域
2.用类名作用域来调用方法
3.可以任意访问对象的私有成员，仅限于不依赖对象的成员（只能调用其它的static静态成员）

const常成员方法 => const CGoods *this
1.属于类的作用域
2.调用依赖一个对象，普通对象或者常对象都可以
3.可以任意访问对象的私有成员，但是只能读，而不能写
*/
class CDate {
public:
	CDate(int year, int month, int day) {
		_year = year;
		_month = month;
		_day = day;
	}
	void show() const {
		cout << _year << '/' << _month << '/' << 'day' << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
/*
构造函数的初始化列表  :  可以指定当前对象成员变量的初始化方式
Cdate信息  CGoods商品信息的一部分  a part of...  组合的关系
*/
class CGoods {
public:
	// “CDate”: 没有合适的默认构造函数可用
	CGoods(const char* name, int amount, double price, int y, int m, int d)
		// #1 构造函数的初始化列表
		:_date(y, m, d)   // CDate _date(y, m, d);
		, _amount(amount) // int _amount = amount;
		, _price(price) {
		// #2 当前类类型构造函数体
		strcpy(_name, name);
		// _amount = amount; // int _amount; _amount = amount;
		// _date(y, m, n);   // CDate _date; _date = CDate(y, m, d); // 这样是不行的，应为CDate没有默认的构造函数了，不能先构造再赋值

		_count++; // 记录所有产生的新对象的数量
	}
	// 普通成员方法
	void show() { // 打印商品的私有信息 CGoods *this
		cout << "name:" << _name << "\n";
		cout << "amount:" << _amount << "\n";
		cout << "price:" << _price << endl;
		_date.show();
	}
	// 常成员方法    只要是只读操作的成员方法，一律实现成const常成员方法
	void show() const { // const CGoods *this
		cout << "name:" << _name << "\n";
		cout << "amount:" << _amount << "\n";
		cout << "price:" << _price << endl;
		_date.show();
	}
	// 静态成员方法 没有this指针的
	static void showCGoodsCount() { // 打印的是所有商品共享的信息
		cout << "所有商品的种类的数量是 : " << _count << endl;
	}
private:
	char _name[20];
	int _amount;
	double _price;
	CDate _date;        // 成员对象  1.分配内存  2.调用构造函数
	static int _count;  // 不属于对象，而是属于类级别的 声明 用来记录商品对象的总数量
};
// static成员变量一定要在类外进行定义并且初始化
int CGoods::_count = 0;

int main() {
	CGoods good1("C", 100, 10, 2024, 11, 29);
	good1.show();

	CGoods good2("C++", 100, 10, 2024, 11, 29);
	good2.show();

	CGoods good3("python", 100, 10, 2024, 11, 29);
	good3.show();

	CGoods good4("Go", 100, 10, 2024, 11, 29);
	good4.show();

	// 统计所有商品的数量
	// good4.showCGoodsCount();
	CGoods::showCGoodsCount();

	const CGoods good5("镇店之宝", 100, 10, 2024, 11, 29);
	good5.show(); // CGoods::show(&good5)    const CGoods *this


	return 0;
}