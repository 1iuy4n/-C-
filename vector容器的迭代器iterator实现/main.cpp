#include <iostream>
using namespace std;
/*
��ģ�� => ʵ��һ��C++ STL�����һ��˳������ vector ��������
SeqStack
Queue
����:
�ռ�������allocator

template <class _Ty, class _Alloc = allocator<_Ty>>
class vector

�����Ŀռ�������allocator ���ļ����� �ڴ濪��/�ڴ��ͷ�    ������/��������
*/
// ���������Ŀռ�����������C++��׼���allocatorʵ��һ��
template<typename T>
class Allocator {
public:
	T* allocate(size_t size) { // �����ڴ濪��
		return (T*)malloc(sizeof(T) * size);
	}
	void deallocate(void* p) { // �����ڴ��ͷ�
		free(p);
	}
	void construct(T* p, const T& val) { // ���������
		new (p) T(val); //��λnew
	}
	void destroy(T* p) { // �����������
		p->~T();
	}
};

/*
�����ײ��ڴ濪�٣��ڴ��ͷţ����������������ͨ��allocator�ռ���������ʵ��
*/
template<typename T, typename Alloc = Allocator<T>>
class vector {
public:
	vector(int size = 5, const Alloc& alloc = Allocator<T>())
		: _allocator(alloc) {
		// ��Ҫ���ڴ濪�ٺͶ�����ֿ�����
		// _first = new T[size];
		_first = _allocator.allocate(size);
		_last = _first;
		_end = _first + size;
	}
	~vector() {
		// ����������Ч��Ԫ�أ�Ȼ���ͷ�_firstָ��ָ��Ķ��ڴ�
		// delete[]_first;
		for (T* p = _first; p != _last; ++p) {
			_allocator.destroy(p); // ��_firstָ��ָ����������ЧԪ�ؽ�����������
		}
		_allocator.deallocate(_first); //�ͷŶ��ϵ��ڴ�
		_first = _last = _end = nullptr;
	}
	vector(const vector<T>& rhs) {
		int size = rhs._end - rhs._first;
		// _first = new T[size];
		_first = _allocator.allocate(size);
		int len = rhs._end - rhs._first;
		for (int i = 0; i < len; ++i) {
			// _first[i] = rhs._first[i];
			_allocator.construct(_first + i, rhs._first[i]);
		}
		_last = _first + len;
		_end = _first + size;
	}
	vector<T>& operator=(const vector<T>& rhs) {
		if (this == &rhs)
			return *this;
		// delete[] _first;
		for (T* p = _first; p != _last; ++p) {
			_allocator.destroy(p); // ��_firstָ��ָ����������ЧԪ�ؽ�����������
		}
		_allocator.deallocate(_first); //�ͷŶ��ϵ��ڴ�

		int size = rhs._end - rhs._first;
		// _first = new T[size];
		_first = _allocator.allocate(size);
		int len = rhs._end - rhs._first;
		for (int i = 0; i < len; ++i) {
			// _first[i] = rhs._first[i];
			_allocator.construct(_first + i, rhs._first[i]);
		}
		_last = _first + len;
		_end = _first + size;
		return *this;
	}
	void push_back(const T& val) { // ������ĩβ���Ԫ��
		if (full())
			expand();
		// *_last++ = val;    _lastָ��ָ����ڴ湹��һ��ֵΪval�Ķ���
		_allocator.construct(_last, val);
		++_last;
	}
	void pop_back() { // ������ĩβɾ��Ԫ��
		if (empty())
			return;
		// --_last;    ����Ҫ��_lastָ��--������Ҫ����ɾ����Ԫ��
		--_last;
		_allocator.destroy(_last);
	}
	T back()const { // ��������ĩβ��Ԫ�ص�ֵ
		return *(_last - 1);
	}
	bool full()const { return _last == _end; }
	bool empty()const { return _last == _first; }
	int size()const { return _last - _first; }
	T& operator[](int index) {
		if (index < 0 || index >= size()) {
			throw "OutOfRangeException";
		}
		return _first[index];
	}

	// ������һ��ʵ�ֳ�������Ƕ������
	class iterator {
	public:
		iterator(T* ptr=nullptr)
			:_ptr(ptr){}
		bool operator!=(const iterator& it)const {
			return _ptr != it._ptr;
		}
		void operator++() {
			++_ptr;
		}
		// ��Ҫ�������ṩbegin��end����
		T& operator*() { return *_ptr; }            // int data = *it; *it = 20;
		const T& operator*()const { return *_ptr; } // int data = *it;
	private:
		T* _ptr;
	};
	// ��Ҫ�������ṩbegin��end����
	iterator begin() { return _first; }
	iterator end() { return _last; }
private:
	T* _first;             // ָ��������ʼ��λ��
	T* _last;              // ָ����������ЧԪ�صĺ��λ��
	T* _end;               // ָ������ռ�ĺ��λ��
	Alloc _allocator;      // ���������Ŀռ�����������

	void expand() {        // �����Ķ�������
		int size = _end - _first;
		// T* ptmp = new T[2 * size];
		T* ptmp = _allocator.allocate(2 * size);
		for (int i = 0; i < size; ++i) {
			// ptmp[i] = _first[i];
			_allocator.construct(ptmp + i, _first[i]);
		}
		// delete[] _first;
		for (T* p = _first; p != _last; ++p) {
			_allocator.destroy(p); // ��_firstָ��ָ����������ЧԪ�ؽ�����������
		}
		_allocator.deallocate(_first);
		_first = ptmp;
		_last = _first + size;
		_end = _first + 2 * size;
	}
};

class Test {
public:
	Test() { cout << "Test()" << endl; }
	~Test() { cout << "~Test()" << endl; }
	Test(const Test&) { cout << "Test(const Test&)" << endl; }
};
int main() {
	vector<int> vec;
	for (int i = 0; i < 20; ++i) {
		vec.push_back(rand() % 100);
	}
	
	int size = vec.size();
	for (int i = 0; i < size; ++i) {
		cout << vec[i] << " ";
	}
	cout << endl;

	for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	for (int val : vec) { // ��ײ�ԭ������ͨ�������ĵ�������ʵ������������
		cout << val << " ";
	}
	cout << endl;

	return 0;
}