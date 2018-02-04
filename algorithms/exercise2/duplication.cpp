/**
## 数组中的重复数字
### Description
在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。

### Solution
* 由于题目已经明确指出所有数字都在0到n-1的范围内, 因此可以借鉴桶排序的思想. 具体思路如下: 
遍历数组, 判断当前位置上的值和下标的值是否相等: 1)如果相等则遍历下一位;2)如果不相等则将当前位置上的值num和a[num]做比较如果不相等则对调,使其满足"1)"的条件,如果相等则说明该元素为重复元素. 

**/

#include <iostream>

using namespace std;

void swap(int& a, int& b){
    int tmp = a;
    a = b;
    b = tmp;
}

bool duplicate(int numbers[], int length, int* duplication) {
    if(!numbers) return false;
    for(int i=0; i<length; ++i){
        if(numbers[i]<0 || numbers[i]>length-1)
            return false;
    }
    
    for(int i=0; i<length; ++i){
        while(numbers[i] != i){
            if(numbers[i] != numbers[numbers[i]]){
                swap(numbers[i], numbers[numbers[i]]);
            }
            else{
                *duplication = numbers[i];
                return true;
            }
        }
    }
    
    return false;
}


int main(){
    
    // int numbers[] = {2,1,3,1,4};
    int numbers[] = {2,3,1,0,2,5,3};
    int length = 5;
    int duplication = -1;
    
    if(duplicate(numbers, length, &duplication)){
        cout<< duplication<< endl;
    }
    else{
        cout<< "-1"<< endl;
    }
    
    return 0;
}