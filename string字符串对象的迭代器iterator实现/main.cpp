#include<iostream>
#include<string>
// char arr[] = "jklsdf"
using namespace std;

// 自己实现一个字符串对象
class String {
public:
	String(const char* p = nullptr) {
		if (p != nullptr) {
			_pstr = new char[strlen(p) + 1];
			strcpy(_pstr, p);
		}
		else {
			_pstr = new char[1];
			*_pstr = '\x00';
		}
	}
	~String() {
		delete[]_pstr;
		_pstr = nullptr;
	}
	String(const String& src) {
		_pstr = new char[strlen(src._pstr) + 1];
		strcpy(_pstr, src._pstr);
	}
	String operator=(const String& src) {
		if (this == &src) {
			return *this;
		}
		delete[]_pstr;
		_pstr = new char[strlen(src._pstr) + 1];
		strcpy(_pstr, src._pstr);
		return *this;
	}
	bool operator>(const String& str)const {
		return strcmp(_pstr, str._pstr) > 0;
	}
	bool operator<(const String& str)const {
		return strcmp(_pstr, str._pstr) < 0;
	}
	bool operator==(const String& str)const {
		return strcmp(_pstr, str._pstr) == 0;
	}
	int length()const { return strlen(_pstr); }
	const char* c_str()const { return _pstr; }
	// char ch = str6[6]; str6[6] = '7';
	char& operator[](int index) { return _pstr[index]; }
	// char ch = str6[6]; 不允许修改str6[6] = '7';
	const char& operator[](int index)const { return _pstr[index]; }

	// 给String字符串类型提供迭代器的实现
	class iterator {
	public:
		iterator(char *p=nullptr):_p(p){}
		bool operator!=(const iterator& it) {
			return _p != it._p;
		}
		void operator++() { ++_p; }
		char& operator*() { return *_p; }
	private:
		char* _p;
	};
	// begin返回的是容器底层首元素的迭代器表示
	iterator begin() { return _pstr; }
	// end返回的是容器末尾元素后继位置的迭代器表示
	iterator end() { return _pstr + length(); }
private:
	char* _pstr;
	friend String operator+(const String& a, const String& b);
	friend ostream& operator<<(ostream& out, const String& src);
};
String operator+(const String& a, const String& b) {
	/*char* p = new char[strlen(a._pstr) + strlen(b._pstr) + 1];
	strcpy(p, a._pstr);
	strcat(p, b._pstr);
	String tmp(p);
	delete[]p;
	return tmp;*/
	String tmp;
	// 必须要有这一步，直接赋值是有问题的，因为默认构造函数会声明一个堆上的chunk
	delete[] tmp._pstr;
	// 直接赋值就丢失了，glibc无法回收构造时的chunk
	tmp._pstr = new char[strlen(a._pstr) + strlen(b._pstr) + 1];
	strcpy(tmp._pstr, a._pstr);
	strcat(tmp._pstr, b._pstr);
	return tmp;

}
ostream& operator<<(ostream& out, const String& src) {
	out << src.c_str();
	return out;
}

int main() {
	// 迭代器的功能: 提供一种统一的方式，来透明地遍历容器
	String str1 = "hello world"; // str1叫容器吗？底层放了一组char类型的字符
	// 容器的迭代器类型
	String::iterator it = str1.begin();
	for (; it != str1.end(); ++it) {
		// 迭代器可以透明的访问容器内部的元素的值
		cout << *it << " ";
	}
	cout << endl;

	// C++11 foreach的方式来遍历容器内部元素的值=>底层还是通过迭代器进行遍历
	for (char ch : str1) {
		cout << ch << " ";
	}
	cout << endl;

	return 0;
}

/*
泛型算法参数接收的都是迭代器!
泛型算法 - 全局的函数 - 给所有容器用的
泛型算法有一套方式能够统一的遍历所有的容器的元素 - 迭代器
*/