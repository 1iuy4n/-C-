#include<iostream>
#include<string>
// char arr[] = "jklsdf"
using namespace std;

// �Լ�ʵ��һ���ַ�������
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
	// char ch = str6[6]; �������޸�str6[6] = '7';
	const char& operator[](int index)const { return _pstr[index]; }

	// ��String�ַ��������ṩ��������ʵ��
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
	// begin���ص��������ײ���Ԫ�صĵ�������ʾ
	iterator begin() { return _pstr; }
	// end���ص�������ĩβԪ�غ��λ�õĵ�������ʾ
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
	// ����Ҫ����һ����ֱ�Ӹ�ֵ��������ģ���ΪĬ�Ϲ��캯��������һ�����ϵ�chunk
	delete[] tmp._pstr;
	// ֱ�Ӹ�ֵ�Ͷ�ʧ�ˣ�glibc�޷����չ���ʱ��chunk
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
	// �������Ĺ���: �ṩһ��ͳһ�ķ�ʽ����͸���ر�������
	String str1 = "hello world"; // str1�������𣿵ײ����һ��char���͵��ַ�
	// �����ĵ���������
	String::iterator it = str1.begin();
	for (; it != str1.end(); ++it) {
		// ����������͸���ķ��������ڲ���Ԫ�ص�ֵ
		cout << *it << " ";
	}
	cout << endl;

	// C++11 foreach�ķ�ʽ�����������ڲ�Ԫ�ص�ֵ=>�ײ㻹��ͨ�����������б���
	for (char ch : str1) {
		cout << ch << " ";
	}
	cout << endl;

	return 0;
}

/*
�����㷨�������յĶ��ǵ�����!
�����㷨 - ȫ�ֵĺ��� - �����������õ�
�����㷨��һ�׷�ʽ�ܹ�ͳһ�ı������е�������Ԫ�� - ������
*/