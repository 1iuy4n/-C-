#include <iostream>
using namespace std;

/*
C++������    ���ú�ָ�������
1.��ֵ���ú���ֵ����
2.���õ�ʵ��

������һ�ָ���ȫ��ָ��
1.�����Ǳ����ʼ���ģ�ָ����Բ���ʼ��
2.����ֻ��һ�����ã�û�ж༶���ã�ָ�������һ��ָ�룬Ҳ�����ж༶ָ��
3.����һ�����ñ������Ͷ���һ��ָ�����������ָ����һģһ���ģ�
ͨ�����ñ����޸��������ڴ��ֵ����ͨ��ָ��������޸�ָ��ָ����ڴ��ֵ����ײ�ָ��Ҳ��һģһ����

��ֵ����
1.int&& c = 20; ר������������ֵ���ͣ�ָ���ϣ������Զ�������ʱ����Ȼ��ֱ��������ʱ�� c = 40;
2.��ֵ���ñ���������һ����ֵ��ֻ������ֵ������������
3.������һ����ֵ���ñ���������һ����ֵ

*/
#if 0
void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
void swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}
int main() {

	int a = 10;
	int b = 20;
	// swap(&a, &b);
	swap(a, b);
	cout << "a: " << a << "  b: " << b << endl;
#endif
#if 0
	int a = 10;
	int* p = &a;
	int& b = a;

	// int& c = 20;

	*p = 20;


	// 20 20 20 a  *p  b
	cout << a << " " << *p << " " << b << endl;
	b = 30;
	// 30 30 30 a  *p  b
	cout << a << " " << *p << " " << b << endl;

	return 0;
}
#endif
#if 0
int main() {
	int array[5] = {};
	int* p = array;
	// ����һ�����ñ�����������array����
	int(&q)[5] = array;

	cout << sizeof(array)<< "  "<< array << endl;
	cout << sizeof(p) << "  " <<p <<endl;
	cout << sizeof(q) << "  " << q<< endl;
}
#endif

int main() {
	int a = 10;  // ��ֵ�������ڴ棬�����֣�ֵ�����޸�
	int& b = a;

	// int& c = 20; // 20����ֵ: û�ڴ棬û����
	// C++11�ṩ����ֵ����
	int&& c = 20;
	c = 30;

	int& e = c; // һ����ֵ���ñ�����������һ����ֵ

	/*
	int temp = 20;
	temp -> d
	*/
	const int& d = 20;

	return 0;
}