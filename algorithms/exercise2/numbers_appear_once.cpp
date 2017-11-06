/*
## 数组中只出现一次的数据
### 题目
>> 一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。

### 思路
注意所给数组的特殊性, `除了两个数字之外其他的数字都出现两次`. 进而联想到`异或`运算的性质: 任何一个数和自己做异或最终的结果都为0.
因此, 如果对整个数组做异或那么最终得到的就是两个不同的数的异或结果. 
可以利用这个异或的结果将数组分成两组,每组只包含一个出现一次的数. 由于两个不同的数一定不相等, 所以整个数组的异或结果一定不为0, 也就是说异或结果的二进制表示中一定至少有一位为1. 将异或结果中第一个为1的位记为第N位, 从而根据第N位是否为1将整个数组划分成两组.

*/

#include <iostream>
#include <vector> 

using namespace std;

void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
    int res_xor = 0;
    for(int i=0; i<data.size(); ++i){
        res_xor ^= data[i];
    }
    // cout<< "res_xor "<< res_xor<< endl;
    
    int flag = 1;
    while(!(res_xor&flag)){
        flag <<= 1;
    }
    // cout<< "flag "<< flag<< endl;
    
    *num1 = 0;
    *num2 = 0;
    for(int i=0; i<data.size(); ++i){
        if(data[i]&flag){
            *num1 ^= data[i];
        }
        else{
            *num2 ^= data[i];
        }
    }
}

int main(){
    int data_size = 0;
    vector<int> data;
    int tmp;
    
    cin>> data_size;
    for(int i=0; i<data_size; ++i){
        cin>> tmp;
        data.push_back(tmp);
    }
    
    int num1 = 0; 
    int num2 = 0;
    FindNumsAppearOnce(data, &num1, &num2);
    cout<< "numbers appear once: "<< num1<< " " << num2<< endl;
    
    return 0;
}