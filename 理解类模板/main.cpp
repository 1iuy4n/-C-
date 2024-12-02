#include <iostream>
using namespace std;


/*
函数模板
模板的非类型参数 必须是整数类型（整数或者地址/引用都可以）都是常量，只能使用，而不能修改

类模板 => 实例化 => 模板类

*/

// 类模板
template<typename T=int>
class SeqStack { // 模板名称+类型参数列表 = 类名称
public:
	// 构造函数和析构函数名不用加<T>，其它出现模板的地方都加上类型参数列表
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
		// 不要用memcopy进行拷贝
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
		// 不要用memcopy进行拷贝
		for (int i = 0; i < _top; i++) {
			_pstack[i] = stack._pstack[i];
		}
		return *this;
	}

	void push(const T& val); // 入栈操作

	void pop() { // 出栈操作
		if (empty())
			return;
		--_top;
	}
	T top() const {
		if (empty())
			throw "stack is empty!"; // 抛出异常也代表函数逻辑结束
		return _pstack[_top - 1];
	}
	bool full()const {  // 栈满
		return _top == _size;
	}
	bool empty()const { // 栈空
		return _top == 0;
	}
private:
	T* _pstack;
	int _top;
	int _size;

	// 顺序栈底层数组按2倍的方式扩容
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
void SeqStack<T>::push(const T& val) { // 入栈操作
	if (full())
		expand();
	_pstack[_top++] = val;
}



int main() {
	// 类模板的选择性实例化
	// 模板类 class SeqStack<int>{};
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
	const int size = sizeof(arr) / sizeof(arr[0]); // 编译时期直接计算
	// size位置这里必须是一个常量 
	sort<int, size>(arr);
	for (int num : arr) {
		cout << num << " ";
	}
	cout << endl;

	return 0;
}
#endif
