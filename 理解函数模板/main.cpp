#include <iostream>
using namespace std;

/*
C++ ����ģ��
ģ������� : ������Ҳ���Խ��в�������
int sum(int a, int b) {return a+b;}

����ģ��        <=    �ǲ����б���ģ���Ϊ���ͻ���֪��
ģ���ʵ����    <=    �������õ����ʵ����
ģ�庯��        <=    ����Ҫ���������������

ģ�����Ͳ��� typename/class
ģ������Ͳ���

ģ���ʵ������ => ���Ը����û������ʵ�ε����ͣ����Ƶ���ģ�����Ͳ����ľ�������

ģ�����������ר�û��� ���⣨���Ǳ������ṩ�ģ������û��ṩ�ģ���ʵ����
����ģ�塢ģ�������������ģ�庯�������ع�ϵ

ģ������ǲ�����һ���ļ��ж��壬������һ���ļ���ʹ�õ�
ģ��������֮ǰ��һ��Ҫ����ģ�嶨��ĵط��������Ļ���
ģ����ܽ���������ʵ�����������ܹ�������������Ĵ���

���ԣ�ģ����붼�Ƿ���ͷ�ļ��еģ�Ȼ����Դ�ļ�����ֱ�ӽ���#include����
*/
/*
// ����ģ��
template<typename T>     // ����һ��ģ������б�
bool compare(T a, T b) { // compare��һ������ģ��
	cout << "template compare" << endl;
	return a > b;
}
*/

/*
�ں������õ㣬���������û�ָ�������ͣ���ԭģ��ʵ����һ�ݺ����������ģ�庯��
bool compare<int>(int a, int b){
    return a>b;
}
bool compare<double>(double a, double b){
	return a>b;
}
bool compare<const char*>(const char* a, const char* b){
	return strcmp(a, b) > 0;
}
*/
/*
// ���compare����ģ�壬�ṩconst char*���͵��������汾
template<>
bool compare(const char* a, const char* b) {
	cout << "compare<const char*>" << endl;
	return strcmp(a, b) > 0;
}

// ��ģ�庯�� - ��ͨ����
bool compare(const char* a, const char* b) {
	cout << "normal compare" << endl;
	return strcmp(a, b) > 0;
}
*/
// ģ�������
template<typename T>
bool compare(T a, T b);    // compare < const char* > *UND*

bool compare(const char* a, const char* b);

int main() {
	// "bool __cdecl compare<int>(int,int)" (??$compare@H@@YA_NHH@Z)
	// "bool __cdecl compare<double>(double,double)" (??$compare@N@@YA_NNN@Z)
	// �����ĵ��õ�
	compare<int>(10, 20);
	compare<double>(10.5, 20.5);

	// ����ģ��ʵ�ε�����
	compare(10, 20);
	compare<int>(10, 30.0);

	// ����ģ��ʵ�ε����� T const char*
	// ����ĳЩ������˵������������Ĭ��ʵ������ģ����룬���봦���߼����д����
	// ���������Ȱ�compare����ɺ������֣�û�еĻ�����ȥ��compareģ��
	compare("aaaa", "bbbb");
	compare < const char* >("aaa", "bbb");

	return 0;
}