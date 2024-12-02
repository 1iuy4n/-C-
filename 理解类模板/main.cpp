#include <iostream>
using namespace std;


/*
����ģ��
ģ��ķ����Ͳ��� �������������ͣ��������ߵ�ַ/���ö����ԣ����ǳ�����ֻ��ʹ�ã��������޸�

��ģ�� => ʵ���� => ģ����

*/

// ��ģ��
template<typename T=int>
class SeqStack { // ģ������+���Ͳ����б� = ������
public:
	// ���캯�����������������ü�<T>����������ģ��ĵط����������Ͳ����б�
	SeqStack<T>(int size = 10)
		: _pstack(new T[size])
		, _top(0)
		, _size(size) {}
	~SeqStack<T>() {
		delete[] _pstack;
		_pstack = nullptr;
	}
	SeqStack<T>(const SeqStack<T>& stack)
		:_top(stack._top)
		, _size(stack._size) {
		_pstack = new T[_size];
		// ��Ҫ��memcopy���п���
		for (int i = 0; i < _top; i++) {
			_pstack[i] = stack._pstack[i];
		}
	}
	SeqStack<T>& operator = (const SeqStack<T>&stack){
		if (this == &stack)
			return *this;

		top = stack._top;
		_size = stack._size;
		_pstack = new T[_size];
		// ��Ҫ��memcopy���п���
		for (int i = 0; i < _top; i++) {
			_pstack[i] = stack._pstack[i];
		}
		return *this;
	}

	void push(const T& val); // ��ջ����

	void pop() { // ��ջ����
		if (empty())
			return;
		--_top;
	}
	T top() const {
		if (empty())
			throw "stack is empty!"; // �׳��쳣Ҳ�������߼�����
		return _pstack[_top - 1];
	}
	bool full()const {  // ջ��
		return _top == _size;
	}
	bool empty()const { // ջ��
		return _top == 0;
	}
private:
	T* _pstack;
	int _top;
	int _size;

	// ˳��ջ�ײ����鰴2���ķ�ʽ����
	void expand() {
		T* _ptmp = new T[_size * 2];
		for (int i = 0; i < _top; i++) {
			_ptmp[i] = _pstack[i];
		}
		delete[]_pstack;
		_pstack = _ptmp;
		_size *= 2;
	}
};

template<typename T>
void SeqStack<T>::push(const T& val) { // ��ջ����
	if (full())
		expand();
	_pstack[_top++] = val;
}



int main() {
	// ��ģ���ѡ����ʵ����
	// ģ���� class SeqStack<int>{};
	SeqStack<int> s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.pop();
	cout << s1.top() << endl;

	SeqStack<> s2;

	return 0;
}


#if 0
template<typename T, int SIZE>
void sort(T* arr) {
	for (int i = 0; i < SIZE - 1; ++i) {
		for (int j = 0; j < SIZE - 1 - i; ++j) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
int main() {

	int arr[] = {12,5,7,89,32,21,35};
	const int size = sizeof(arr) / sizeof(arr[0]); // ����ʱ��ֱ�Ӽ���
	// sizeλ�����������һ������ 
	sort<int, size>(arr);
	for (int num : arr) {
		cout << num << " ";
	}
	cout << endl;

	return 0;
}
#endif
