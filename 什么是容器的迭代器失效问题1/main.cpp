#include <iostream>
#include <vector>
using namespace std;

/*
�����ĵ�����ʧЧ���⣿
1.������Ϊʲô��ʧЧ��
a:����������erase�����󣬵�ǰλ�õ�����ĩβԪ�ص����е�λ�õĵ�����ȫ��ʧЧ��
b:����������insert�����󣬵�ǰλ�õ�����ĩβԪ�ص����е�λ�õĵ�����ȫ��ʧЧ��
    ��������Ȼ��Ч         ������ȫ��ʧЧ
��Ԫ��    ->    �����/ɾ����    ->    ĩβԪ��

c:��insert��˵��������������ڴ�����
       ԭ�����������е�������ȫ��ʧЧ��
��Ԫ��    ->    �����/ɾ����    ->    ĩβԪ��

d:��ͬ�����ĵ������ǲ��ܽ��бȽ������

2.������ʧЧ���Ժ��������ô�����
�Բ���/ɾ����ĵ��������и��²���
*/
int main() {
	vector<int> vec;
	for (int i = 0; i < 20; ++i) {
		vec.push_back(rand() % 100 + 1);
		cout << vec[i] << " ";
	}
	cout << endl;

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

#if 0
	// ��vec���������е�ż��ȫ��ɾ��
	for (auto it = vec.begin(); it != vec.end();) {
		if (*it % 2 == 0) {
			// ������ʧЧ�����⣬��һ�ε���erase�Ժ󣬵�����it��ʧЧ��
			// vec.erase(it);
			it= vec.erase(it); // insert(it, val)    erase(it)
			// break;
		}
		else {
			++it;
		}
	}
#endif
	for (int v : vec) {
		cout << v << " ";
	}
	cout << endl;

	return 0;
}