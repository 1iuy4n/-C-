#include <iostream>
using namespace std;
/*
===> inline�������� �� ��ͨ���������𣿣���
inline��������: �ڱ�������У���û�к����ĵ��ÿ����ˣ�
�ں����ĵ��õ�ֱ�ӰѺ����Ĵ������չ��������

inline��������������Ӧ�ĺ�������

inlineֻ�ǽ������������������������������
���ǲ������е�inline���ᱻ������������������� - �ݹ�

debug�汾�ϣ�inline�ǲ������õģ� inlineֻ����release�汾�²��ܳ���
g++ -c main.cpp -O2    objdump -t main.o
-g��debug�汾
*/
inline int sum(int x, int y) { // *.o    sum_int_int    .text
	return x + y;
}

int main() {
	int a = 10;
	int b = 20;

	int ret = sum(a, b);
	// �˴��б�׼�ĺ������ù���    ����ѹջ������ջ֡�Ŀ��ٺͻ��˹����к����ĵ��ÿ���
	// x+y mov add mov        1000000 x+y

	return 0;
}