#include <iostream>
#include <typeinfo>
using namespace std;
/*
��������
1.C++Ϊʲô֧�ֺ������أ�C���Բ�֧�ֺ�������
C++��������������ŵ�ʱ�򣬺�����+�����б�������ɵ�!
C��������������ŵ�ʱ�򣬺�������������

2.����������Ҫע��Щʲô
3.C++��C���Դ���֮������໥����

ʲô�Ǻ������أ�
1.һ�麯�������к�������ͬ�������б�ĸ����������Ͳ�ͬ����ô��һ�麯���ͳ���-��������
2.һ�麯��Ҫ�Ƶ������أ�һ�����Ǵ���ͬһ���������е�
3.const����volatile�ĵ�ʱ������ôӰ���β����͵�
4.һ�麯������������ͬ�������б�Ҳ��ͬ�������Ƿ���ֵ��ͬ����������

�������һ�£�ʲô�Ƕ�̬��
��̬������ʱ�ڣ��Ķ�̬: ��������
��̬������ʱ�ڣ��Ķ�̬:

ʲô�Ǻ������أ�

C ���� C++:�޷�ֱ�ӵ�����!��ô�죿 ��C++��������������extern "C"���
C++ ���� C����:�޷�ֱ�ӵ�����!��ô�죿 ��C��������������extern "C"���
*/
// __FILE__
// __LINE__
// ֻҪ��C++����������������__cplusplus�������

#ifdef __cplusplus
extern "C" {
#endif
	int sum(int a, int b) { // sum_int_int  .text
		return a + b;
	}
#ifdef __cplusplus
}
#endif


#if 0
extern "C" {
	int sum(int a, int b) { // sum_int_int  .text
		return a + b;
	}
}
// �޷��������ⲿ����
// "int __cdecl sum(int,int)" (? sum@@YAHHH@Z)������ main �������˸÷���
extern "C" {
	int sum(int a, int b); // sum  "UND"
}

int main() {
	int ret = sum(10, 20);
	cout << "ret:" << ret << endl;

	return 0;
}


void func(int *a){}  // int
void func(int *const a){}// int
int main() {

	int a = 10;
	const int b = 10;

	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;

	return 0;
}
#endif
#if 0
bool compare(int a, int b) { // compare_int_int
	cout << "compare_int_int" << endl;
	return a > b;
}
bool compare(double a, double b) { // compare_double_double
	cout << "compare_double_double" << endl;
	return a > b;
}
bool compare(const char* a, const char* b) { // compare_const char*_const char*
	cout << "compare_char*_char*" << endl;
	return strcmp(a, b) > 0;
}
int data = 10;
int main() {
	int data = 20;
	int a = ::data;


	bool compare(int a, int b); // ����������

	compare(10, 20);
	compare(10.0, 20.0); // double -> int
	compare("aaa", "bbb"); // const char* -> int

	return 0;
}
#endif