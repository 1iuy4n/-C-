#include <iostream>
using namespace std;
/*
const��һ��ָ�룬���õĽ��ʹ��
*/
int main() {
	// int a = 10;
	// int* p = &a;
	// const int*& q = p;
	// const int** q = &p; // const int** <= int**

	// int a = 10;
	// const int* p = &a;
	// int*& q = p;
	// int** q = &p;
	// int** <= const int**

	// int a = 10;
	// int* const p = &a;
	// int*& q = p; <=> int** q = &p;


	// дһ����룬���ڴ��0x0018ff44��дһ��4�ֽڵ�10
	int* p = (int*)0x0018ff44;
	// int* const& p = (int*)0x0018ff44;
	// int*&& p = (int*)0x0018ff44;
	cout << p << endl;
	int a = 10;
	cout << &a << endl;
	*p = a;
	// const int*& q = p; <=> const int** q = &p; 
	

	return 0;
}