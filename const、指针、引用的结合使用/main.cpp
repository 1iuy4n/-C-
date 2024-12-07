#include <iostream>
using namespace std;
/*
const，一级指针，引用的结合使用
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


	// 写一句代码，在内存的0x0018ff44出写一个4字节的10
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