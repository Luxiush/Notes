/*
## 把数组排成最小的数
### 题目
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

### 思路
* 重新定义比较运算:
1. ab < ba ==> a < b 
2. ab > ba ==> a > b 
3. ab == ba ==> a == b
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        sort(numbers.begin(), numbers.end(), _cmp);
        stringstream res;
        for(int i=0; i<numbers.size(); ++i){
            res<< numbers[i];
        }
        return res.str();
    }
    
    static bool _cmp(int a, int b){
        stringstream s_a, s_b;
        s_a << a<< b;
        s_b << b<< a;
        return s_a.str()<s_b.str();
    }
};

int main(){
    int arr[] = {3, 32, 321};
    int len = sizeof(arr)/sizeof(int);
    vector<int> V;
    for(int i=0; i<len; ++i){
        V.push_back(arr[i]);
    }
    
    Solution S;
    cout<< S.PrintMinNumber(V)<< endl;
    
    return 0;
}