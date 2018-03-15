/**
## 求1+2+3+...+n
### 题目:
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
### [解法]( http://blog.csdn.net/shoulinjun/article/details/20564095 ):
#### 递归:
* A||B: 当 A为true时，B不再执行.
* 利用这一性质模拟选择语句,实现递归.

#### 模板
...

#### 类
* 采用C++类中的static变量,以及构造函数在对象构造时会被自动调用的性质。
**/
#include <iostream>

using namespace std;

/*******/
int Sum(int n) {
	int res = 0;
	// A || B: 当 A为true时，B不再执行也就起到了选择的作用
	(n==0)||(res=Sum(n-1));
	return res+n;
}

/*******/
class MyClass{
	static int n;
	static int sum;

	MyClass(){
		n += 1;
		sum += n;
	}
};

/*******/


int main(){
	cin>> n;

	cout<< "Solutioon 1: "<< Sum(n)<< endl;

	int MyClass::n = 0;
	int MyClass::sum = 0;
	MyClass a[n];  // 调用n次构造函数
	cout<< "Solutioon 2: "<< MyClass::sum<< endl;

	return 0;
}
