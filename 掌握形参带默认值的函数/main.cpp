#include <iostream>
using namespace std;

/*
===> �βδ�Ĭ��ֵ�ĺ���
1.��Ĭ��ֵ��ʱ�򣬴��������
2.����Ч�ʵ�����
3.���崦���Ը��β�Ĭ��ֵ������Ҳ���Ը��β�Ĭ��ֵ
4.�βθ�Ĭ��ֵ��ʱ�򣬲����Ƕ��崦�������������������β�Ĭ��ֵֻ�ܳ���һ��
*/
// sum(, 20);
int sum(int a, int b = 20);
int sum(int a = 10, int b);
int main() {
	int a = 10;
	int b = 20;
	int ret = sum(a, b);
	/*
	mov eax, dword ptr[ebp-8]
	push eax
	mov ecx, dword ptr[ebp-4]
	push ecx
	call sum
	*/
	cout << "ret:" << ret << endl;

	/*
	push 14H
	mov ecx, dword ptr[ebp-4]
	push ecx
	call sum
	*/
	ret = sum(a);

	/*
	push 14H
	push 0AH
	call sum
	*/
	ret = sum(); // sum(20, 50)

	return 0;
}
int sum(int a, int b) {
	return a + b;
}