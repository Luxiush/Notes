/*
## ��1+2+3+...+n
### ��Ŀ: 
��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����
### [�ⷨ]( http://blog.csdn.net/shoulinjun/article/details/20564095 ): 
#### �ݹ�: 
* A||B: �� AΪtrueʱ��B����ִ��.
* ������һ����ģ��ѡ�����,ʵ�ֵݹ�.

#### ģ��
...

#### ��
* ����C++���е�static����,�Լ����캯���ڶ�����ʱ�ᱻ�Զ����õ����ʡ�
*/
#include <iostream>

using namespace std;

/*******/
int Sum(int n) {
	int res = 0;
	// A || B: �� AΪtrueʱ��B����ִ��Ҳ������ѡ�������
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
	MyClass a[n];  // ����n�ι��캯��
	cout<< "Solutioon 2: "<< MyClass::sum<< endl;
	
	return 0;
}