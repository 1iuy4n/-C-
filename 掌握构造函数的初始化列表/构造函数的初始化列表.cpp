#include <iostream>
using namespace std;

class Test {
public:
	Test(int data=10) : mb(data), ma(mb){}
	void show() { cout << "ma:" << ma << " mb:" << mb << endl; }
private:
	// ��Ա�����ĳ�ʼ�������Ƕ����˳���йأ��͹��캯����ʼ���б��г��ֵ��Ⱥ�˳���޹�!
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
���캯���ĳ�ʼ���б�  :  ����ָ����ǰ�����Ա�����ĳ�ʼ����ʽ
Cdate��Ϣ  CGoods��Ʒ��Ϣ��һ����  a part of...  ��ϵĹ�ϵ
*/
class CGoods {                                                 
public:
	// ��CDate��: û�к��ʵ�Ĭ�Ϲ��캯������
	CGoods(const char* name, int amount, double price, int y, int m, int d)
		// #1 ���캯���ĳ�ʼ���б�
		:_date(y, m, d)   // CDate _date(y, m, d);
		, _amount(amount) // int _amount = amount;
		, _price(price) {
		// #2 ��ǰ�����͹��캯����
		strcpy(_name, name);
		// _amount = amount; // int _amount; _amount = amount;
		// _date(y, m, n);   // CDate _date; _date = CDate(y, m, d); // �����ǲ��еģ�ӦΪCDateû��Ĭ�ϵĹ��캯���ˣ������ȹ����ٸ�ֵ
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
	CDate _date; // ��Ա����  1.�����ڴ�  2.���ù��캯��
};

int main() {
	CGoods good("C++", 100, 10, 2024, 11, 29);
	good.show();

	return 0;
}
#endif