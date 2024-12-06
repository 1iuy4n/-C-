/*
int sum(int a, int b) { // sum  .text
	return a + b;
}
*/


#include <stdio.h>

// 无法解析的外部符号 sum
int sum(int a, int b); // sum *UND*
int main() {
	int ret = sum(10, 20);
	printf("ret:%d\n", ret);

	return 0;
}