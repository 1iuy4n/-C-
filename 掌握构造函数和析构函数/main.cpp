#include <iostream>

using namespace std;

/*
���캯������������
OOPʵ��һ��˳��ջ

���캯������������
���������ֺ�����һ��
û�з���ֵ
*/
class SeqStack {
public:
	// ���캯��
	SeqStack(int size = 10) { // �ǿ��Դ������ģ���˿����ṩ������캯�������翽�����캯��
		cout << this << "SeqStack()" << endl;
		_pstack = new int[size];
		_top = -1;
		_size = size;
	}
	// ��������
	~SeqStack() { // �ǲ��������ģ�������������ֻ����һ��
		cout << this << "~SeqStack()" << endl;
		delete[]_pstack;
		 _pstack = nullptr;
	}
	/*void init(int size = 10) {
		_pstack = new int[size];
		_top = -1;
		_size = size;
	}
	void release () {
		delete[]_pstack;
		_pstack = nullptr;
	}*/
	void push(int val) {
		if (full())
			resize();
		_pstack[++_top] = val;
	}
	void pop() {
		if (empty())
			return;
		--_top;
	}
	int top() { return _pstack[_top]; }
	bool empty() { return _top == -1; }
	bool full() { return _top == _size - 1; }
private:
	int* _pstack; //��̬�������飬��ȡ˳��ջ��Ԫ��
	int _top;     //ָ��ջ��Ԫ�ص�λ��
	int _size;    //�������ݵ��ܴ�С
	void resize() {
		int* ptmp = new int[_size * 2];
		for (int i = 0; i < _size; ++i) {
			ptmp[i] = _pstack[i];
		}
		delete[]_pstack;
		_pstack = ptmp;
		_size *= 2;
	}
};

SeqStack gs;

int main() {
	/*
	.data
	heap
	stack
	*/

	SeqStack* ps = new SeqStack(20); // malloc�ڴ濪��+SeqStack(20)������
	ps->push(70);
	ps->push(80);
	ps->pop();
	cout << ps->top() << "\n���ڴ��ͷţ�";
	delete ps;// �ȵ���ps->~SeqStack()Ȼ��free(ps)

	// 1.�����ڴ�    2.���ù��캯��
	SeqStack s;
	//s.init(5); // �����Ա�����ĳ�ʼ������

	for (int i = 0; i < 15; ++i) {
		s.push(rand() % 100);
	}
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << "\n";

	//s.release(); //�ͷŶ����Ա����ռ�õ��ⲿ���ڴ棨�ⲿ��Դ��

	SeqStack s1;
	/*
	s1.~SeqStack(); // �����������ú󣬶��󲻴�����
	cout << s1.top(); // ���ڴ�ķǷ����ʣ���Ϊ~SeqStack()�Ὣ_pstack��Ϊ��ָ��
	// ��ʹ����ע�͵�~SeqStack()�е�_pstack = nullptr;
	// ��linux��Ҳ�����free(): double free detected in tcache 2
	// ��Ϊlinux��main��������ʱ�������һ��s1.~SeqStack()���ᱻglibc������double free
	*/

	return 0;
}