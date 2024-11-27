#include <iostream>

using namespace std;

// 循环队列
class Queue {
public:
	Queue(int size = 20) {
		_pQue = new int[size];
		_front = _rear = 0;
		_size = size;
	}
	Queue(const Queue& src) {
		_pQue = new int[src._size];
		_front = src._front;
		_rear = src._rear;
		_size = src._size;
		for (int i = _front; i != _rear; i = (i + 1) % _size) {
			_pQue[i] = src._pQue[i];
		}
	}
	Queue& operator=(const Queue& src) {
		if(this!=&src){
			return *this;
		}
		_pQue = new int[src._size];
		_front = src._front;
		_rear = src._rear;
		_size = src._size;
		for (int i = _front; i != _rear; i = (i + 1) % _size) {
			_pQue[i] = src._pQue[i];
		}
		return *this;
	}
	~Queue() {
		delete[] _pQue;
		_pQue = nullptr;
	}
	void push(int val) {        // 入队操作
		if (full())
			resize();
		_pQue[_rear] = val;
		_rear = (_rear + 1) % _size;
	}
	void pop() {                // 出队操作
		if (empty())
			return;
		_front = (_front + 1) % _size;
	}
	int front() {              // 获取队头元素
		return _pQue[_front];
	}
	bool full() {
		return (_rear + 1) % _size == _front;
	}
	bool empty() {
		return _rear == _front;
	}

private:
	int* _pQue; // 申请队列的数组空间
	int _front; // 指示队头的位置
	int _rear;  // 指示队尾的位置
	int _size;  // 队列扩容的总大小
	void resize() {
		int* ptmp = new int[_size * 2];
		int index = 0;
		for (int i = _front; i != _rear; i = (i + 1) % _size) {
			ptmp[index++] = _pQue[i];
		}
		delete[]_pQue;
		_pQue = ptmp;
		_front = 0;
		_rear = index;
		_size *= 2;
	}
};

int main0() {

	Queue queue;
	for (int i = 0; i < 20; ++i) {
		queue.push(rand() % 100);
	}
	while (!queue.empty()) {
		cout << queue.front() << " ";
		queue.pop();
	}
	cout << endl;

	Queue queue1 = queue;
	queue1 = queue;

	return 0;
}