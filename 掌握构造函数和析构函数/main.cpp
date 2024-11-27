#include <iostream>

using namespace std;

/*
构造函数和析构函数
OOP实现一个顺序栈

构造函数和析构函数
函数的名字和类名一样
没有返回值
*/
class SeqStack {
public:
	// 构造函数
	SeqStack(int size = 10) { // 是可以带参数的，因此可以提供多个构造函数，比如拷贝构造函数
		cout << this << "SeqStack()" << endl;
		_pstack = new int[size];
		_top = -1;
		_size = size;
	}
	// 析构函数
	~SeqStack() { // 是不带参数的，所以析构函数只能有一个
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

SeqStack gs;

int main() {
	/*
	.data
	heap
	stack
	*/

	SeqStack* ps = new SeqStack(20); // malloc内存开辟+SeqStack(20)对象构造
	ps->push(70);
	ps->push(80);
	ps->pop();
	cout << ps->top() << "\n堆内存释放：";
	delete ps;// 先调用ps->~SeqStack()然后free(ps)

	// 1.开辟内存    2.调用构造函数
	SeqStack s;
	//s.init(5); // 对象成员变量的初始化操作

	for (int i = 0; i < 15; ++i) {
		s.push(rand() % 100);
	}
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << "\n";

	//s.release(); //释放对象成员变量占用的外部堆内存（外部资源）

	SeqStack s1;
	/*
	s1.~SeqStack(); // 析构函数调用后，对象不存在了
	cout << s1.top(); // 堆内存的非法访问，因为~SeqStack()会将_pstack置为空指针
	// 即使我们注释掉~SeqStack()中的_pstack = nullptr;
	// 在linux下也会检测出free(): double free detected in tcache 2
	// 因为linux下main函数结束时还会调用一次s1.~SeqStack()，会被glibc检查出来double free
	*/

	return 0;
}