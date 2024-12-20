#include <iostream>
#include <typeinfo>
using namespace std;

/*
1.�̳еı��ʺ�ԭ��
2.������Ĺ������
3.���ء����ǡ�����
4.��̬�󶨺Ͷ�̬��
5.��̬ vfptr��vftable
6.����������ԭ��
7.���ؼ̳��Լ�����
8.����� vbptr��vbtable
9.RTTI
10.C++��������ǿת
11.�̳ж�̬�����������������
*/


/*
����һ����Щ��������ʵ�ֳ��麯����

�麯��������
1.�麯���ܲ�����ַ���洢��vftable����
2.���������ڣ�vfptr -> vftable ->�麯����ַ)

���캯��
1.virtual+���캯�� NO��
2.���캯���У����õ��κκ��������Ǿ�̬�󶨵ģ������麯����Ҳ���ᷢ����̬��
�������������� 1.�ȵ��õ��ǻ���Ĺ��캯�� 2.�ŵ���������Ĺ��캯��

static��̬��Ա���� NO�� virtual + static

�����������������  �����������õ�ʱ�򣬶����Ǵ��ڵģ�
ʲôʱ��ѻ����������������ʵ�ֳ��麯����
�����ָ�루���ã�ָ�����new����������������ʱ��delete pb�������ָ�룩��
����������������ʱ�򣬱��뷢����̬�󶨣�����ᵼ������������������޷�����
*/

class Base {
public:
	Base(int data) :ma(data) { cout << "Base()" << endl; }
	// ����������
	virtual ~Base() { cout << "~Base()" << endl; }
	virtual void show() { cout << "call Base::show()" << endl; }
protected:
	int ma;
};// &Base::~Base  &Base::show
class Derive :public Base {  // &Derive::~Derive  &Derive::show
public:
	Derive(int data) :Base(data), mb(data), ptr(new int(data)) { cout << "Derive()" << endl; }
	// ���������������virtual�麯������ô����������������Զ���Ϊ�麯��
	~Derive() { cout << "~Derive()" << endl; }
private:
	int mb;
	int* ptr;
};


int main() {
	Base* pb = new Derive(10);
	pb->show(); // ��̬�� pb Base*  *pb
	delete pb;
	/*
	pb->Base  Base::~Base  �������������ĵ��ã����Ǿ�̬����
	call Base::~Base

	pb->Base  Base::~Base()  �������������ĵ��ã����Ƕ�̬����
	pb -> Derive  Derive vftable  &Derive::~Derive
	*/

	/*Derive d(10);
	Base* pb = &d;
	pb->show();*/

	return 0;
}