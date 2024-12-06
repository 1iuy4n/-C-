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
int main() {

#if 0
	int a = 10;
	const int* p = &a; // const int*  <=  int*
	int* q = p;        // int*        <=  const int*

	int a = 10;
	int* const p = &a; // int*       <= int*
	const int* q = p;  // const int* <= int*

	int a = 10;
	int* const p = &a; // int* <= int*
	int* q = p;        // int* <= int*

	int a = 10;
	int* const p = &a; // int* <= int*
	int* const q = p;  // int* <= int*

	int a = 10;
	int* p = &a;
	const int** q = &p;
	// *q <=> p

	int a = 10;
	int* p = &a;
	int* const* q = &p; //const* <= *

	int a = 10;
	int* p = &a;
	int** const q = &p; // int** <= int**

	int a = 10;
	int* const p = &a; // int*   <= int*
	int** q = &p;      // *      <= const*

	int a = 10;
	const int* p = &a;
	int* const* q = &p; // int*  <=  const int*

#endif

	return 0;
}