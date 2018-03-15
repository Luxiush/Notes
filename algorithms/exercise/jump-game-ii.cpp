/**
##　lettcode jump-game-ii
### 题目
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.

### 思路
#### v1 贪心
＜http://www.cnblogs.com/grandyang/p/4373533.html＞
<https://www.sigmainfy.com/blog/leetcode-jump-game-ii.html>


#### v2 动态规划
类似狄杰斯特拉算法, 遍历一遍输入序列, 更新当前所能到达的位置的步数.
```
 2   3   1   3   4   1   3   5   1      输入序列
[0] _1_ _1_  I   I   I   I   I   I      i = 0
 0  [1] _1_ _2_ _2_  I   I   I   I      i = 1
 0   1  [1] _2_  2   I   I   I   I      i = 2
 0   1   1  [2]  2   3   3   I   I      ...
 0   1   1   2  [2]  3   3   3   3
 0   1   1   2   2  [3]  3   3   3
 0   1   1   2   2   3  [3]  3   3
 0   1   1   2   2   3   3  [3]  3
 0   1   1   2   2   3   3   3  [3]

```

```python
def Jump(arr):
    steps = [INF] * len(arr)
    steps[0] = 0

    for i in range(len(arr)):
        for e in range(1,arr[i]+1):
            next = i+e
            if(next < len(steps)):
                steps[next] = min(steps[next], steps[i]+1)

    return steps[len(arr)-1]
```

**/
#include <iostream>
#include <vector>

using namespace std;
// 贪心
int jump(int A[], int n) {
    if(n<2) return 0;

    int cur = 0;
    int next = 0;
    int steps = 0;
    int i = 0;

    for(; i<n; ++i){
        if(i>next){
            ++ steps;
            next = cur;
        }

        if(cur<i+A[i]){
            cur = i+A[i];
        }
    }
    return steps;
}

int main(){
	int A[100];
	int n;
	cin >> n;
	for(int i=0; i<n; ++i)
		cin>> A[i];

	cout<< jump(A,n)<< endl;


	return 0;
}
