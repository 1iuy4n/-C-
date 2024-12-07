#include <iostream>
using namespace std;

/*
new��delete
1.malloc��new������
a.malloc���ֽڿ����ڴ�ģ�new�����ڴ�ʱ��Ҫָ������ new int[10]
  ����malloc�����ڴ淵�صĶ���void*    operator new -> int*
b.mallocֻ���𿪱ٿռ䣬new��������malloc�Ĺ��ܣ����Խ������ݵĳ�ʼ��
  new int(20);    new int[20]();    int()
c.malloc�����ڴ�ʧ�ܷ���nullptrָ�룻new�׳�����bad_alloc���͵��쳣
2.free��delete������
delete (int*)p: ����������������free(p)

new -> operator new
delete -> operator delete


new��delete�ܻ�����C++Ϊʲô���ֵ���Ԫ�غ�������ڴ������ͷ��أ�
new delete
new[] delete[]
������ͨ�ı������������� new/delete[]  new[]/delete

�Զ���������ͣ�������������Ϊ�˵�����ȷ��������������ô���ٶ��������ʱ���࿪��4���ֽڣ���¼����ĸ���
*/
// �ȵ���operator new�����ڴ�ռ䣬Ȼ����ö���Ĺ��캯������ʼ����
void* operator new(size_t size) {
	void* p = malloc(size);
	if (p == nullptr)
		throw bad_alloc();
	cout << "operator new addr:" << p << endl;
	return p;
}
void* operator new[](size_t size) {
	void* p = malloc(size);
	if (p == nullptr)
		throw bad_alloc();
	cout << "operator new[] addr:" << p << endl;
	return p;
}
// delete p;  ����ָ�����������������ٵ���operator delete�ͷ��ڴ�ռ�
void operator delete(void* ptr) {
	cout << "operator delete addr" << ptr << endl;
	free(ptr);
}
void operator delete[](void* ptr) {
	cout << "operator delete[] addr" << ptr << endl;
	free(ptr);
}
class Test {
public:
	Test(int data = 10) { cout << "Test()" << endl; }
	~Test() { cout << "~Test()" << endl; }
private:
	int ma;
};
int main() {
	// Test* p1 = new Test();
	// delete[] p1;

	/*
	operator new[] addr:0000028A546757A0
	Test()
	Test()
	Test()
	Test()
	Test()
	~Test()
	operator delete addr0000028A546757A8
	*/
	Test* p2 = new Test[5];
	cout << "p2:" << p2 << endl;
	delete p2;

#if 0
	try {
		int* p = new int(10);
		delete p;
		
		int* q = new int[10];
		delete[]q;
	}
	catch (const bad_alloc& err) {
		cerr << err.what() << endl;
	}
#endif
	return 0;
}