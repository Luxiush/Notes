/**
## 最大差值
### 题目
有一个长为n的数组A，求满足0≤a≤b<n的A[b]-A[a]的最大值。max给定数组A及它的大小n，请返回最大差值。

### 思路
- 动态规划: 遍历一遍数组, 记录当前最小值和最大差值.

**/

#include <iostream>
#include <stdlib.h>

using namespace std;

int MaxDist(int A[], int n)
{
    int minEle = A[0];
    int maxDist = 0;
    for(int i=0; i<n; i++){
        if(A[i]-minEle > maxDist){
            maxDist = A[i]-minEle;
        }
        if(A[i] < minEle) minEle = A[i];
    }
    return maxDist;
}


int main(){
    const int MAX_SIZE = 1000;
    int A[MAX_SIZE];
    int n;
    cin >> n;
    for(int i=0; i<n; i++)cin >> A[i];
    cout<< MaxDist(A, n)<< endl;

    return 0;
}
