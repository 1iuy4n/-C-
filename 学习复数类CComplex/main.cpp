#include <iostream>
using namespace std;

/*
C++����������� : ʹ�����������ֵúͱ�������������һ��
template<typename T>
T sum(T a, T b){
    return a+b; // a.operator+(b)
}
������
*/
class CComplex {
public:
	// CComlex() CComplex(20) CComplex(20, 20)
	CComplex(int r = 0, int i=0) : mreal(r), mimage(i){}
	// ָ����������ô��CComplex�����ļӷ�����
	//CComplex operator+(const CComplex& src) {
	//	// CComplex comp;
	//	// comp.mreal = this->mreal + src.mimage;
	//	// comp.mimage = this->mimage + src.mimage;
	//	// return comp;
	//	return CComplex(this->mreal + src.mreal, this->mimage + src.mimage);
	//}
	CComplex operator++(int) {
		 // CComplex comp = *this;
		 // mreal += 1;
		 // mimage += 1;
		 // return comp;
		 return CComplex(this->mreal++, this->mimage++);
	}
	CComplex& operator++() {
		this->mreal += 1;
		this->mimage += 1;
		return *this;
	}
	void operator+=(const CComplex& src) {
		this->mreal += src.mreal;
		this->mimage += src.mimage;
	}
	void show() { cout << "real:" << mreal << " image:" << mimage << endl; }
private:
	int mreal;
	int mimage;

	friend CComplex operator+(const CComplex& lhs, const CComplex& rhs);
	friend ostream& operator<<(ostream& out, const CComplex& src);
	friend istream& operator>>(istream& in, const CComplex& src);
};
CComplex operator+(const CComplex& lhs, const CComplex& rhs) {
	return CComplex(lhs.mreal + rhs.mreal, lhs.mimage + rhs.mimage);
}
ostream& operator<<(ostream& out, const CComplex& src) {
	out << "mreal:" << src.mreal << " mimage:" << src.mimage << endl;
	return out;
}
istream& operator>>(istream& in, CComplex& src) {
	int real, image;
	cin >> real >> image;
	src = CComplex(real, image);
	return in;
}
int main() {
	CComplex comp1(10, 10);
	CComplex comp2(20, 20);
	// comp1.operator+(comp2) �ӷ�����������غ���
	CComplex comp3 = comp1 + comp2;
	// CComplex comp3 = comp1.operator+(comp2);
	comp3.show();

	CComplex comp4 = comp1 + 20; // comp4.operator+(20) int->CComplex CComplex(int)
	comp4.show();
	// �����������������ʱ�򣬻���ö������������غ��������ȵ��ó�Ա��������
	// ���û�г�Ա�������ͻ���ȫ���������Һ��ʵ���������غ���
	//        ::operator+(30, comp1)
	CComplex comp5 = 30 + comp1;
	comp5.show();

	// CComplex operator++(int)
	comp5 = comp1++;  // ++ --��Ŀ����� operator++() ǰ��++    operator++(int) ����++
	comp1.show();
	comp5.show();
	// CComplex operator++()
	comp5 = ++comp1;
	comp1.show();
	comp5.show();

	// void comp1.operator+=(comp2)        ::operator+=(comp1, comp2)
	comp1 += comp2;
	// comp1.show();  // ������Ϣ�����
	// cout ::operator<<(cout, comp1)    void << endl;
	// ostream& operator<<(ostream &out, const CComplex &src)
	cout << comp1 << endl;
	cin >> comp1 >> comp2;
	cout << comp1 << comp2 << endl;

	return 0;
}

template<typename T>
void show(T a) { // CComplex a
	// a.show();
	cout << a << endl; // T int cout<<10<<endl;    CComplex
}