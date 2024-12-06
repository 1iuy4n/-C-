#include <iostream>
#include <typeinfo>
using namespace std;

/*
const��һ��ָ��Ľ��
const�Ͷ������༶��ָ��Ľ��

const���ε���    �г���
��ͨ������������ʲô��  C++����������1.���뷽ʽ��ͬ  2.������Ϊ��ֵ��

const���ε��������ֵĴ����ǣ�
1.������������Ϊ��ֵ��  <=  ֱ���޸ĳ�����ֵ
2.���ܰѳ����ĵ�ַй¶��һ����ͨ��ָ�������ͨ�����ñ���  <=  ���Լ���޸ĳ�����ֵ

cosnt��һ��ָ��Ľ��:���������
C++�����Թ淶: const���ε����������������
const int* p = &a;  =>  *p = 20  p = &b
��������ָ��ͬ��int���͵��ڴ棬���ǲ���ͨ��ָ�����޸�ָ����ڴ��ֵ
int const* p;

int *const p = &a;  =>  p = &b;  *p = 20;
���ָ��p�����ǳ�����������ָ�������ڴ棬���ǿ���ͨ��ָ��������޸�ָ����ڴ��ֵ

const int *const p = &a;  // *p = &b  p = 

const����ұ�û��ָ��*�Ļ���const�ǲ��������͵�

�ܽ�cosnt��ָ�������ת����ʽ:
int*         <=  const int*    �Ǵ����!
const int*   <=  int*          �ǿ��Ե�!

int**        <=  const int**   �Ǵ����!
const int**  <=  int**         �Ǵ����!

int**        <=  int*const*    �Ǵ����!
int*const*   <=  int**         �ǿ��Ե�!
*/
int main01() {
	// int a = 10;
	// const int* p = &a;
	// int* q = p; // int* <= const int*
	// cout << typeid(p).name() << endl;

	// int* q1 = nullptr;  // NULL
	// int* const q2 = nullptr;
	// cout << typeid(q1).name() << endl;
	// cout << typeid(q2).name() << endl;
	// // const����ұ�û��ָ��*�Ļ���const�ǲ��������͵�

	// int a = 10;
	// int* p1 = &a;
	// const int* p2 = &a; // const int * <= int*
	// int* const p3 = &a; // int*        <= int*
	// int* p4 = p3;       // int*        <= int*

	// int b = 20;
	// int* q = &b;

	// const int a = 10;
	// int* p = &a;  // *p = 30;    int* <= const int*
	// const int* p = &a;

	return 0;
}

/*
const�Ͷ���ָ��Ľ��
*/
int main() {
	int a = 10;
	int* p = &a;
	// const int*p = &a; ����const int* const* q = &p;
	const int** q = &p; // const int **  <=  int **
	/*
	const int **q = &p;;
	          *q <=> q
	  const int b = 20;
	           *q = &b;
	*/

	return 0;
}