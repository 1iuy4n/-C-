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
�麯������̬�󶨺Ͷ�̬��

���ǣ�
�����������ķ���������ֵ���麯�����Լ������б���ͬ�����һ���ķ������麯����
��ô������ķ������Զ�������麯��������֮���Ϊ���ǹ�ϵ

һ����������麯�������������ʲôӰ�죿
�ܽ�һ��
��������涨�����麯������ô����׶Σ�����������������Ͳ���һ��Ψһ��vftable�麯����
�麯��������Ҫ�洢�����ݾ���RTTIָ����麯���ĵ�ַ��
����������ʱ��ÿһ���麯��������ص��ڴ��.rodata��

�ܽ����
һ�������涨�����麯������ô����ඨ��Ķ���
������ʱ���ڴ濪ʼ���֣���洢һ��vfptr�麯��ָ�룬
ָ����Ӧ���͵��麯����vftable��
һ�����Ͷ����n���������ǵ�vfptrָ��Ķ���ͬһ���麯����

�ܽ�����
һ���������麯���ĸ�������Ӱ������ڴ��С��vfptr����Ӱ������麯����Ĵ�С
*/
class Base {
public:
	Base(int data=10):ma(data){}
	// �麯��
	virtual void show() { cout << "Base::show()" << endl; }
	// �麯��
	virtual void show(int) { cout << "Base::show(int)" << endl; }
protected:
	int ma;
};
class Derive : public Base {
public:
	Derive(int data=20):Base(data), mb(data){}
	/*
	�ܽ��ģ�
	����������еķ������ͻ���̳�����ĳ������������ֵ���������������б���ͬ��
	���һ���ķ�����virtual��������ô�����������������Զ�������麯��
	��д ��=������
	���ǣ��麯�������麯����ַ�ĸ���
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
	pb->Base Base::show �������show����ͨ�������ͽ��о�̬��
	                                             call Base::show()
	pb->Base Base::show �������show���麯�����ͽ��ж�̬����
	mov eax, dword ptr[pb]
	mov ecx, dword ptr[eax]
	call ecx(�麯���ĵ�ַ)  ��̬������ʱ�ڣ��İ󶨣������ĵ��ã�
	*/
	pb->show();   // ��̬������ʱ�ڣ��İ󶨣������ĵ��ã�call        Base::show (07FF7257A13F7h)
	
	/*
	Base::show(int)  ��һ���麯������ʱ�͵ö�̬����
	mov eax, dword ptr[pb]
	mov ecx, dword ptr[eax]
	call ecx(�麯���ĵ�ַ)  ��̬������ʱ�ڣ��İ󶨣������ĵ��ã�
	*/
	pb->show(10); // ��̬�� call        Base::show (07FF7A28710DCh)

	cout << sizeof(Base) << endl;   // 4 16
	cout << sizeof(Derive) << endl; // 8 24
	/*
	��Ҫע���������sizeof��Ӧ��������Ĵ�С��/d1reportSingleClassLayout�Ĵ�С��һ��
	sizeof��ӡ��Base��Derive�Ĵ�С�ֱ��� 16 �� 24
	/d1reportSingleClassLayout����ʾ��Ľṹ�������ģ���ʾ�Ĵ�С�ֱ��� 8 �� 16��
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
	֮������ֵ�Բ�������Ϊsizeof����������ֽڣ�
	��������sizeTest�Ĳ��ԣ�sizeof��ӡ�����Ĵ�С��16����d1reportSingleClassLayout�еĽṹ���£�
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
	pb�����ͣ�Base->û���麯��
	���Baseû���麯����*pbʶ��ľ��Ǳ���ʱ�ڵ�����  *pb <=> Base����
	���Base���麯����*pbʶ��ľ�������ʱ�ڵ�����  RTTI����
	pb->d(vfptr)->Derive vftable class Derive
	*/
	cout << typeid(*pb).name() << endl; // class Base
	/*
	Base������show����������ͨ�ĺ���
	Base::show()
	Base::show(int)
	4
	8
	class Base * __ptr64
	class Base
	*/

	/*
	��Base������show���������virtual�麯����
	Derive::show()
	Base::show(int)
	16
	24
	class Base * __ptr64
	class Derive
	*/

	return 0;
}