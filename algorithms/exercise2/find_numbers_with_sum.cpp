/**
## 和为S的俩个数
### 题目
输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，如果有多对数字的和等于S，输出两个数的**乘积最小的**。

### 思路
双指针:
if 和小于S: 小指针++
if 和大于S: 大指针--
直到两个指针的和等于S

* 当量指针离得最远时, 就是乘积最小的时候. 所以通过以上方法最先找到的就是乘积最小的. 

**/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> arr,int sum) {
        int len = arr.size();
        vector<int> res;
        if(len<2) return res;
        int i_min = 0;
        int i_max = len-1;
        while(i_min<i_max){
            if(arr[i_min]+arr[i_max]<sum)
                i_min ++;
            else if(arr[i_min]+arr[i_max]>sum)
                i_max --;
            else{
                res.push_back(arr[i_min]);
                res.push_back(arr[i_max]);
                break;
            }
        }
        return res;
    }
};

int main(){

    return 0
}