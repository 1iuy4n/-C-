#include <iostream>
#include <typeinfo>
using namespace std;


/*
const和一级指针的结合
const和二级（多级）指针的结合

const修饰的量    叫常量
普通变量的区别是什么？  C++有两点区别？1.编译方式不同  2.不能作为左值了

const修饰的量常出现的错误是：
1.常量不能再作为左值了  <=  直接修改常量的值
2.不能把常量的地址泄露给一个普通的指针或者普通的引用变量  <=  可以间接修改常量的值

cosnt和一级指针的结合:有两种情况
C++的语言规范: const修饰的是离它最近的类型
const int* p = &a;  =>  *p = 20  p = &b
可以任意指向不同的int类型的内存，但是不能通过指针间接修改指向的内存的值
int const* p;

int *const p = &a;  =>  p = &b;  *p = 20;
这个指针p现在是常量，不能再指向其它内存，但是可以通过指针解引用修改指向的内存的值

const int *const p = &a;  // *p = &b  p =

const如果右边没有指针*的话，const是不参与类型的

总结cosnt和指针的类型转换公式:
int*         <=  const int*    是错误的!
const int*   <=  int*          是可以的!

int**        <=  const int**   是错误的!
const int**  <=  int**         是错误的!

int**        <=  int*const*    是错误的!
int*const*   <=  int**         是可以的!
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