#include <iostream>
#include <typeinfo>
using namespace std;
/*
const  ָ��  ����  �ں������е�����
const��ô��⣿
const���εı������ܹ�����Ϊ��ֵ!!!��ʼ����ɺ�ֵ���ܱ��޸�!!!

C��C++��const��������ʲô��
const�ı��뷽ʽ��ͬ��C�У�const���ǵ���һ����������������ָ���
C++�У����г���const�������ֵĵط������������ĳ�ʼ���滻��!!!

C++��const
�����ʼ���ģ��г���

*/

int main() {
	

	// const int a = 20;  // �Ѿ�����!!!
	// int array[a] = {};

	int b = 20;
	const int a = b; // �г�����  ��Ϊ��ʼֵ��������������һ������    30 30 30

	int* p = (int*)&a;
	*p = 30;

	// 20 30 20
	printf("%d %d %d", a, *p, *(&a));

	return 0;
}