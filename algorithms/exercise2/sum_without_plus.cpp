/**
## 求两个数的和
### 题目
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。

### 思路
1. 各位相加不计进位 (^)
2. 只记下各位相加后的进位 (&)
3. 将前面两步的结果相加(递归), 直到不再产生进位

**/

#include <iostream>

using namespace std;

    int Add(int a, int b){
        if(!b) return a;
        return Add(a^b,(a&b)<<1);
    }

int main(){
    int a, b;
    while(cin>> a>> b){
        cout<< Add(a,b)<< " "<< a+b<< endl<< endl;
    }

    return 0;
}
