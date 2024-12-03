#include<iostream>
#include<string>
// char arr[] = "jklsdf"
using namespace std;

// 自己实现一个字符串对象
class String{
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
		_pstr = new char[strlen(src._pstr)+1];
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
	String str1;
	String str2 = "aaa"; // string(const char*)
	String str3 = "bbb";
	String str4 = str2 + str3;
	String str5 = str2 + "ccc";
	String str6 = "ddd" + str2;
	
	cout << "str6 : " << str6 << endl;
	// bool operator>(const String &str)
	if (str5 > str6) {
		cout << str5 << " > " << str6 << endl;
	}
	else {
		cout << str5 << " < " << str6 << endl;
	}

	int len = str6.length();
	for (int i = 0; i < len; ++i) {
		//      str6.operator[](i)
		cout << str6[i] << " ";
	}
	cout << endl;

	// string ->char*
	char buf[1024] = { 0 };
	strcpy(buf, str6.c_str());
	cout << "buf:" << buf << endl;

	return 0;
}