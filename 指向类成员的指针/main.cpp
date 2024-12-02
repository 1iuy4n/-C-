#include <iostream>
using namespace std;
/*
ָ�����Ա����Ա�����ͳ�Ա��������ָ��
*/
class Test {
public:
	static void staticFunc() { cout << "call Test::staticFunc" << endl; }
	void func() { cout << "call Test::func" << endl; }
	static void static_func() { cout << "Test::static_func" << endl; }
	int ma;
	static int mb;
};
int Test::mb;
int main() {
	Test t1;
	Test* t2 = new Test();

	// ָ���Ա������ָ��
	// �޷��ӡ�void (__cdecl Test::* )(void)��ת��Ϊ��void (__cdecl *)(void)��
	void(Test:: *pfunc)() = &Test::func;
	(t1.*pfunc)();
	(t2->*pfunc)();

	// ��ζ��庯��ָ��ָ�����static��Ա�����أ�
	void (*pStaticFunc)() = &Test::staticFunc;
	pStaticFunc();

#if 0
	// int a=10; int *p=&a; *p=30;
	// �޷��ӡ�int Test::* ��ת��Ϊ��int *��
	int Test::* p = &Test::ma;
	t1.*p = 20;
	cout << t1.*p << endl;

	t2->*p = 30;
	cout << t2->*p << endl;

	int* p1 = &Test::mb;
	*p1 = 40;
	cout << *p1 << endl;
#endif
	delete t2;
	return 0;
}