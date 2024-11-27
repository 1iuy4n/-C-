#include <iostream>

using namespace std;

class SeqStack {
public:
	// 构造函数
	SeqStack(int size = 10) { // 是可以带参数的，因此可以提供多个构造函数，比如拷贝构造函数
		cout << this << "SeqStack()" << endl;
		_pstack = new int[size];
		_top = -1;
		_size = size;
	}
	// 自定义拷贝构造函数 <- 对象的浅拷贝现在有问题
	SeqStack(const SeqStack& src) {
		cout << "SeqStack(const SeqStack& src)" << endl;
		_pstack = new int[src._size];
		for (int i = 0; i <= src._top; ++i) {
			_pstack[i] = src._pstack[i];
		}
		_top = src._top;
		_size = src._size;
	 }
	// 析构函数
	~SeqStack() { // 是不带参数的，所以析构函数只能有一个
		cout << this << "~SeqStack()" << endl;
		delete[]_pstack;
		_pstack = nullptr;
	}
	// 赋值重载函数
	void operator=(const SeqStack& src) {
		cout << "operator=" << endl;
		 //防止自赋值
		if (this == &src) {
			return;
		}
		// 需要先释放当前对象占用的外部资源
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
	int* _pstack; //动态开辟数组，存取顺序栈的元素
	int _top;     //指向栈顶元素的位置
	int _size;    //数组扩容的总大小
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

	SeqStack s;        // 没有定义任何构造函数时，会生成默认构造函数和默认析构函数
	SeqStack s1(10);
	SeqStack s2 = s1;  // 默认拷贝构造函数 -> 直接内存数据拷贝
	//SeqStack s2(s1); 

	// s2.operator=(s1)
	// void operator=(const SeqStack &src)
	s2 = s1;           //  默认的赋值函数 -> 直接内存数据拷贝
	
	s1.push(30); 
	s1.push(20);
	s1 = s1;           // 自赋值，void operator=(const SeqStack &src)中如果不考虑this == &src的情况，编译器不会报错
	s1.push(10);       // 但是s1.pstack会变成一个野指针，原先的数据会丢失
	while (!s1.empty()) {
		cout << s1.top() << " ";
		s1.pop();
	}
	cout << endl;

	return 0;
}