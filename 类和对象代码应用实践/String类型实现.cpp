#include <iostream>

using namespace std;

class String {
public:
	String(const char* str = nullptr){         // 普通构造函数
		if (str != nullptr) {
			m_data = new char[strlen(str) + 1];
			strcpy(this->m_data, str);
		}
		else {
			m_data = new char[1];
			*m_data = '\x00';
		}
	}
	String(const String& other) {              // 拷贝构造函数
		m_data = new char[strlen(other.m_data) + 1];
		strcpy(m_data, other.m_data);
	}
	~String(void) {                            // 析构函数
		delete[] m_data;
		m_data = nullptr;
	}
	// String& 是为了支持连续的operator=赋值操作
	String& operator=(const String& other) {   // 赋值重载函数
		if (this == &other) {
			return *this;
		}
		delete[] m_data;
		m_data = new char[strlen(other.m_data) + 1];
		strcpy(m_data, other.m_data);
		return *this;
	}
private:
	char* m_data;
};


int main() {

	// 调用带const char* 的构造函数
	String str1;
	String str2("hello");
	String str3 = "world";

	// 调用拷贝构造函数
	String str4 = str3;
	String str5(str3);

	// 调用赋值重载函数
	/*
	str1 = str2
	str1.operator=(str2) -> str1
	str3 = str1
	*/
	str3 = str1 = str2;

	return 0;
}