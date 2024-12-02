#include <iostream>

using namespace std;

/*
��ĸ��ֳ�Ա - ��Ա����/����
��ͨ�ĳ�Ա���� => �����������һ��this�βα���
1.�������������
2.���ø÷���ʱ����Ҫ����һ�����󣨳��������޷����õ� ʵ�� : const CGoods*    CGoods *this��
3.����������ʶ����˽�г�Ա����    protected�̳�    public    private

static��̬��Ա���� => ��������this�β�
1.�������������
2.�����������������÷���
3.����������ʶ����˽�г�Ա�������ڲ���������ĳ�Ա��ֻ�ܵ���������static��̬��Ա��

const����Ա���� => const CGoods *this
1.�������������
2.��������һ��������ͨ������߳����󶼿���
3.����������ʶ����˽�г�Ա������ֻ�ܶ���������д
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

		_count++; // ��¼���в������¶��������
	}
	// ��ͨ��Ա����
	void show() { // ��ӡ��Ʒ��˽����Ϣ CGoods *this
		cout << "name:" << _name << "\n";
		cout << "amount:" << _amount << "\n";
		cout << "price:" << _price << endl;
		_date.show();
	}
	// ����Ա����    ֻҪ��ֻ�������ĳ�Ա������һ��ʵ�ֳ�const����Ա����
	void show() const { // const CGoods *this
		cout << "name:" << _name << "\n";
		cout << "amount:" << _amount << "\n";
		cout << "price:" << _price << endl;
		_date.show();
	}
	// ��̬��Ա���� û��thisָ���
	static void showCGoodsCount() { // ��ӡ����������Ʒ�������Ϣ
		cout << "������Ʒ������������� : " << _count << endl;
	}
private:
	char _name[20];
	int _amount;
	double _price;
	CDate _date;        // ��Ա����  1.�����ڴ�  2.���ù��캯��
	static int _count;  // �����ڶ��󣬶��������༶��� ���� ������¼��Ʒ�����������
};
// static��Ա����һ��Ҫ��������ж��岢�ҳ�ʼ��
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

	// ͳ��������Ʒ������
	// good4.showCGoodsCount();
	CGoods::showCGoodsCount();

	const CGoods good5("���֮��", 100, 10, 2024, 11, 29);
	good5.show(); // CGoods::show(&good5)    const CGoods *this


	return 0;
}