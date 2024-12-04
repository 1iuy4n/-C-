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
		// erase(it);        verify(it._ptr, _last);
		// insert(it, val);  verify(it._ptr, _last);
		verify(_last - 1, _last);
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

	//insert erase

	// ������һ��ʵ�ֳ�������Ƕ������
	/*
	iterator
	T* _ptr;
	vector<T, Alloc>* _ptr;
	*/
	class iterator {
	public:
		friend class vector<T, Alloc>;
		iterator(vector<T, Alloc>* pvec = nullptr, T* ptr = nullptr)
			:_ptr(ptr), _pVec(pvec) { // �����ɵ�ǰ����ĳһ��λ��Ԫ�صĵ�����
			Iterator_Base* itb = new Iterator_Base(this, _pVec->_head._next);
			_pVec->_head._next = itb;
		}
		bool operator!=(const iterator& it)const {
			// ������������Ч��
			if (_pVec == nullptr || _pVec != it._pVec) {
				throw "iterator incompatable!";
			}
			return _ptr != it._ptr;
		}
		void operator++() {
			// ������������Ч��
			if (_pVec == nullptr) {
				throw "iterator invalid!";
			}
			++_ptr;
		}
		// ��Ҫ�������ṩbegin��end����
		T& operator*() {
			// ������������Ч��
			if (_pVec == nullptr) {
				throw "iterator invalid!";
			}
			return *_ptr;
		}   // int data = *it; *it = 20;
		const T& operator*()const {
			// ������������Ч��
			if (_pVec == nullptr) {
				throw "iterator invalid!";
			}
			return *_ptr;
		}   // int data = *it;
	private:
		T* _ptr;
		// ��ǰ�����ĵ��������ĸ���������
		vector<T, Alloc>* _pVec;
	};
	// ��Ҫ�������ṩbegin��end����
	iterator begin() { return iterator(this, _first); }
	iterator end() { return iterator(this, _last); }

	//��������ʧЧ
	void verify(T* first, T* last) {
		Iterator_Base* pre = &this->_head;
		Iterator_Base* it = this->_head._next;
		while (it != nullptr) {
			if (it->_cur->_ptr > first && it->_cur->_ptr <= last) {
				// ������ʧЧ����iterator���е�����ָ����nullptr
				it->_cur->_pVec = nullptr;
				// ɾ����ǰ�������ڵ㣬�����жϺ���ĵ������ڵ��Ƿ�ʧЧ
				pre->_next = it->_next;
				delete it;
				it = pre->_next;
			}
			else {
				pre = it;
				it = it->_next;
			}
		}
	}

	// �Զ���vector����insert������ʵ��
	iterator insert(iterator it, const T& val) {
		/*
		1.����������  verify(_first-1, _last);
		2.������it._ptr��ָ��Ϸ���
		*/
		verify(it._ptr - 1, _last);
		T* p = _last;
		while (p > it._ptr) {
			_allocator.construct(p, *(p - 1));
			_allocator.destroy(p - 1);
			--p;
		}
		_allocator.construct(p, val);
		++_last;
		return iterator(this, p);
	}

	// �Զ���vector����erase������ʵ��
	iterator erase(iterator& it) {
		verify(it._ptr - 1, _last);
		T* tmp = it._ptr;
		T* p = it._ptr;
		while (p < _last-1) {
			_allocator.destroy(p);
			_allocator.construct(p, *(p + 1));
			++p;
		}
		_allocator.destroy(p);
		--_last;
		return iterator(this, it._ptr);
	}
private:
	T* _first;             // ָ��������ʼ��λ��
	T* _last;              // ָ����������ЧԪ�صĺ��λ��
	T* _end;               // ָ������ռ�ĺ��λ��
	Alloc _allocator;      // ���������Ŀռ�����������

	// ����������ʧЧ���Ӵ���
	struct Iterator_Base {
		Iterator_Base(iterator* c = nullptr, Iterator_Base* n = nullptr)
			: _cur(c), _next(n) {}
		iterator* _cur;
		Iterator_Base* _next;
	};
	Iterator_Base _head;

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
	vector<int> vec(200);
	for (int i = 0; i < 20; ++i) {
		vec.push_back(rand() % 100 + 1);
		cout << vec[i] << " ";
	}
	cout << endl;

	// ��vec���������е�ż��ȫ��ɾ��
	for (auto it = vec.begin(); it != vec.end();) {
		if (*it % 2 == 0) {
			// ������ʧЧ�����⣬��һ�ε���erase�Ժ󣬵�����it��ʧЧ��
			// vec.erase(it);
			it = vec.erase(it); // insert(it, val)    erase(it)
			// break;
		}
		else {
			++it;
		}
	}
#if 0
	// ��vec���������е�ż��ǰ�����һ��С��ż��ֵ1������
	for (auto it = vec.begin(); it != vec.end(); ++it) {
		if (*it % 2 == 0) {
			// ����ĵ������ڵ�һ��insert֮��iterator��ʧЧ��
			// vec.insert(it, *it - 1);
			it = vec.insert(it, *it - 1);
			++it;
			// break;
		}
	}
#endif
	for (int v : vec) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}