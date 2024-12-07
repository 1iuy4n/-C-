#include <stdlib.h>
#include <iostream>
using namespace std;

/*
new��delete
new��malloc��������ʲô��
delete��free��������ʲô��

malloc��free������C�Ŀ⺯��
new��delete�����������

new�����������ڴ濪�٣����������ڴ��ʼ������
malloc�����ڴ�ʧ�ܣ���ͨ������ֵ��nullptr���Ƚϣ�
��new�����ڴ�ʧ�ܣ���ͨ���׳�bad_alloc���͵��쳣���жϵ�
*/

int main() {

	// new�ж����֣�
	int* p1 = new int(20);
	int* p2 = new (nothrow) int;
	const int* p3 = new const int(40);

	//��λnew
	int data = 0;
	int* p4 = new (&data) int(50);
	cout << data << endl;

#if 0
	int* p = (int*)malloc(sizeof(int));
	if (p == nullptr) {
		return -1;
	}
	*p = 20;
	free(p);

	int* p1 = new int(20);
	delete p1;

	int* q = (int*)malloc(sizeof(int) * 20);
	if (q == nullptr) {
		return -1;
	}
	free(q);

	// int* q1 = new int[20]; // ����ʼ��
	int* q1 = new int[20](); // 20��int sizeof(int)*20����ʼ����0
	delete[]q1;
#endif

	return 0;
}