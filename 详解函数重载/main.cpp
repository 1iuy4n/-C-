#include <iostream>
#include <typeinfo>
using namespace std;
/*
函数重载
1.C++为什么支持函数重载，C语言不支持函数重载
C++代码产生函数符号的时候，函数名+参数列表类型组成的!
C代码产生函数符号的时候，函数名来决定！

2.函数重载需要注意些什么
3.C++和C语言代码之间如何相互调用

什么是函数重载？
1.一组函数，其中函数名相同，参数列表的个数或者类型不同，那么这一组函数就称作-函数重载
2.一组函数要称得上重载，一定先是处在同一个作用域当中的
3.const或者volatile的的时候，是怎么影响形参类型的
4.一组函数，函数名相同，参数列表也相同，仅仅是返回值不同？不叫重载

请你解释一下，什么是多态？
静态（编译时期）的多态: 函数重载
动态（运行时期）的多态:

什么是函数重载？

C 调用 C++:无法直接调用了!怎么办？ 把C++函数的声明扩在extern "C"里边
C++ 调用 C代码:无法直接调用了!怎么办？ 把C函数的声明扩在extern "C"里边
*/
// __FILE__
// __LINE__
// 只要是C++编译器，都内置了__cplusplus这个宏名

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
// 无法解析的外部符号
// "int __cdecl sum(int,int)" (? sum@@YAHHH@Z)，函数 main 中引用了该符号
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


	bool compare(int a, int b); // 函数的声明

	compare(10, 20);
	compare(10.0, 20.0); // double -> int
	compare("aaa", "bbb"); // const char* -> int

	return 0;
}
#endif