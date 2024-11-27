#include <iostream>

using namespace std;

class SeqStack {
public:
	// ���캯��
	SeqStack(int size = 10) { // �ǿ��Դ������ģ���˿����ṩ������캯�������翽�����캯��
		cout << this << "SeqStack()" << endl;
		_pstack = new int[size];
		_top = -1;
		_size = size;
	}
	// �Զ��忽�����캯�� <- �����ǳ��������������
	SeqStack(const SeqStack& src) {
		cout << "SeqStack(const SeqStack& src)" << endl;
		_pstack = new int[src._size];
		for (int i = 0; i <= src._top; ++i) {
			_pstack[i] = src._pstack[i];
		}
		_top = src._top;
		_size = src._size;
	 }
	// ��������
	~SeqStack() { // �ǲ��������ģ�������������ֻ����һ��
		cout << this << "~SeqStack()" << endl;
		delete[]_pstack;
		_pstack = nullptr;
	}
	// ��ֵ���غ���
	void operator=(const SeqStack& src) {
		cout << "operator=" << endl;
		 //��ֹ�Ը�ֵ
		if (this == &src) {
			return;
		}
		// ��Ҫ���ͷŵ�ǰ����ռ�õ��ⲿ��Դ
		delete[]_pstack;
		_pstack = new int[src._size];
		for (int i = 0; i <= src._top; ++i) {
			_pstack[i] = src._pstack[i];
		}
		_top = src._top;
		_size = src._size;
	}
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


int main() {

	SeqStack s;        // û�ж����κι��캯��ʱ��������Ĭ�Ϲ��캯����Ĭ����������
	SeqStack s1(10);
	SeqStack s2 = s1;  // Ĭ�Ͽ������캯�� -> ֱ���ڴ����ݿ���
	//SeqStack s2(s1); 

	// s2.operator=(s1)
	// void operator=(const SeqStack &src)
	s2 = s1;           //  Ĭ�ϵĸ�ֵ���� -> ֱ���ڴ����ݿ���
	
	s1.push(30); 
	s1.push(20);
	s1 = s1;           // �Ը�ֵ��void operator=(const SeqStack &src)�����������this == &src����������������ᱨ��
	s1.push(10);       // ����s1.pstack����һ��Ұָ�룬ԭ�ȵ����ݻᶪʧ
	while (!s1.empty()) {
		cout << s1.top() << " ";
		s1.pop();
	}
	cout << endl;

	return 0;
}