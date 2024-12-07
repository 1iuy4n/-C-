#include <iostream>
using namespace std;

/*
C++ OOP�������    OOP��̣�thisָ��
C:  ���ָ����ĺ����Ķ���  Struct
C++:��  =>  ʵ��ĳ�������
ʵ�壨���ԡ���Ϊ��  ->  ADT(abstract data type)
 |                       |
����                <- ��ʵ������ �� ������->��Ա����  ��Ϊ->��Ա������

OOP���Ե��Ĵ�������ʲô��
����    ��װ/����    �̳�    ��̬

�� -> ��Ʒʵ��
�����޶���: public���е� private˽�е� protected������
*/
const int NAME_LEN = 20;
class CGoods { // => ��Ʒ�ĳ�����������
public:  // ���ⲿ�ṩ���еķ�����������˽�е�����
	// ����Ʒ���ݳ�ʼ���õ�
	void init(const char* name, double price, int amount);
	// ��ӡ��Ʒ��Ϣ
	void show();
	// ����Ա�����ṩһ��getXXX��setXXX�ķ��� ������ʵ�ֵķ������Զ��������inline����
	void setName(char* name) { strcpy(_name, name); }
	void setPrice(double price) { _price = price; }
	void setAmount(int amount) { _amount = amount; }

	const char* getName() { return _name; }
	double getPrice() { return _price; }
	int getAmount() { return _amount; }
private: // ����һ����˽�еĳ�Ա����
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
	CGoods���Զ��������Ķ���ÿһ���������Լ��ĳ�Ա����
	�������ǹ���һ�׳�Ա����

	show() => ��ô֪�������ĸ��������Ϣ��
	init(name, price, amount) => ��ô֪������Ϣ��ʼ������һ��������أ�

	��ĳ�Ա����һ�����룬���еķ��������������һ��thisָ�룬���յ��ø÷����Ķ���ĵ�ַ
	*/
	// cl �ļ���.cpp /dlreportSingleClassLayout��Ա����
	// �����ڴ��С => ֻ�ͳ�Ա�����й�
	CGoods good1; // ��ʵ������һ������

	// init(&good1, "C", 9, 1024);
	good1.init("C", 9, 1024);
	// show(&good1)
	good1.show();

	good1.setPrice(10.0);
	good1.setAmount(2048);
	good1.show();

	CGoods good2; // ��ʵ������һ������
	good2.init("C++", 10.0, 4096);
	good2.show();

	return 0;
}