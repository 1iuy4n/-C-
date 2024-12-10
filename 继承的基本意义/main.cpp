#include <iostream>
using namespace std;

/*
1.�̳еı��ʺ�ԭ��
2.������Ĺ������
3.���ء����ǡ�����
4.��̬�󶨺Ͷ�̬��
5.��̬ vfptr��vftable
6.����������ԭ��
7.���ؼ̳��Լ�����
8.����� vbptr��vbtable
9.RTTI
10.C++��������ǿת
11.�̳ж�̬�����������������
*/



/*
1.�̳еı��ʺ�ԭ��
�̳еı��ʣ�a.����ĸ��� b.
�����֮��Ĺ�ϵ��
��ϣ�a part of����һ���ֵĹ�ϵ
�̳У�a kind of����һ�ֵĹ�ϵ

�̳з�ʽ    ����ķ����޶�    ������ķ����޶�    ��main)�ⲿ�ķ����޶�
public
            public            public               Y
			protected         protected            N
			private           ���ɼ���             N
protected������ĳ�Ա�ķ����޶����������������ǲ����ܳ����̳з�ʽ�ģ�
			public            protected            N
			protected         protected            N
			private           ���ɼ���             N
private
			public            private              N
			protected         private              N
			private           ���ɼ���             N

�ܽ᣺
1.�ⲿֻ�ܷ��ʶ���public�ĳ�Ա��protected��private�ĳ�Ա�޷�ֱ�ӷ���
2.�ڼ̳нṹ�У�������ӻ�����Լ̳й���private�ĳ�Ա������������ȴ�޷�ֱ�ӷ���
3.protected��private�������ڻ����ж���ĳ�Ա���뱻��������ʣ����ǲ��뱻�ⲿ���ʣ�
��ô�ڻ����У�����س�Ա�����protected�����ģ������������ⲿ����������ʣ�
��ô�ڻ����У��Ͱ���س�Ա�����private˽�еġ�

Ĭ�ϵļ̳з�ʽ��ʲô��
Ҫ��������ʹ��class����ģ�����struct�����
class���������࣬Ĭ�ϼ̳з�ʽ����private˽�е�
struct���������࣬Ĭ�ϼ̳з�ʽ����public���е�
*/
class A {
public:
	A(int _ma, int _mb, int _mc) :ma(_ma), mb(_mb), mc(_mc) {}
	int ma;
protected:
	int mb;
private:
	int mc; // ֻ���Լ�������Ԫ�ܷ���˽�еĳ�Ա
	friend void testFriend(A& src);
};
// �̳� A ����/����    B ������/����
class B : private A {
public:
	B(int _ma, int _mb, int _mc, int _md, int _me, int _mf):
		A(_ma, _mb, _mc), 
		md(_md), me(_me), 
		mf(_mf){}
	int md;
protected:
	int me;
private:
	int mf;
};
class C : public B {
	// ��C���棬����ma�ķ����޶���ʲô�����ɼ��ģ������ܼ̳���
};

void testFriend(A& src) {
	cout << src.mc << endl;
}
int main() {
	A a(0, 1, 2);
	testFriend(a);

	B b(0, 1, -2, 3, 4, 5);
	// testFriend(b);
	cout << b.md << endl;
	return 0;
}