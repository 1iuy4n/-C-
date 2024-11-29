#include <iostream>
using namespace std;

class Test {
public:
	Test(int data=10) : mb(data), ma(mb){}
	void show() { cout << "ma:" << ma << " mb:" << mb << endl; }
private:
	// 成员变量的初始化和它们定义的顺序有关，和构造函数初始化列表中出现的先后顺序无关!
	int ma;  // 0xCCCCCCCC    -858993460
	int mb;
};

int main() {
	Test t;
	t.show();
	
	return 0;
}

#if 0
class CDate {
public:
	CDate(int year, int month, int day){
		_year = year;
		_month = month;
		_day = day;
	}
	void show() {
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
	}
	void show() {
		cout << "name:" << _name << "\n";
		cout << "amount:" << _amount << "\n";
		cout << "price:" << _price << endl;
		_date.show();
	}
private:
	char _name[20];
	int _amount;
	double _price;
	CDate _date; // 成员对象  1.分配内存  2.调用构造函数
};

int main() {
	CGoods good("C++", 100, 10, 2024, 11, 29);
	good.show();

	return 0;
}
#endif