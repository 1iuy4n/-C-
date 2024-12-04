#include <iostream>
#include <vector>
using namespace std;

/*
容器的迭代器失效问题？
1.迭代器为什么会失效》
a:当容器调用erase方法后，当前位置到容器末尾元素的所有的位置的迭代器全部失效了
b:当容器调用insert方法后，当前位置到容器末尾元素的所有的位置的迭代器全部失效了
    迭代器依然有效         迭代器全部失效
首元素    ->    插入点/删除点    ->    末尾元素

c:就insert来说，如果引起容器内存扩容
       原来容器的所有迭代器就全部失效了
首元素    ->    插入点/删除点    ->    末尾元素

d:不同容器的迭代器是不能进行比较运算的

2.迭代器失效了以后，问题该怎么解决？
对插入/删除点的迭代器进行更新操作
*/
int main() {
	vector<int> vec;
	for (int i = 0; i < 20; ++i) {
		vec.push_back(rand() % 100 + 1);
		cout << vec[i] << " ";
	}
	cout << endl;

	// 给vec容器中所有的偶数前面添加一个小于偶数值1的数字
	for (auto it = vec.begin(); it != vec.end(); ++it) {
		if (*it % 2 == 0) {
			// 这里的迭代器在第一次insert之后，iterator就失效了
			// vec.insert(it, *it - 1);
			it = vec.insert(it, *it - 1);
			++it;
			// break;
		}
	}

#if 0
	// 把vec容器中所有的偶数全部删除
	for (auto it = vec.begin(); it != vec.end();) {
		if (*it % 2 == 0) {
			// 迭代器失效的问题，第一次调用erase以后，迭代器it就失效了
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