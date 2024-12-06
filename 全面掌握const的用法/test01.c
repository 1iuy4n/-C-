#include <stdio.h>

/*
const修饰的量，可以不用初始化
不叫常量，叫做常变量
*/
void main0() {

	const int a = 20;
	// int array[a] = {};

	int* p = (int*)&a;
	*p = 30;

	// 30 30 30
	printf("%d %d %d", a, *p, *(&a));
}