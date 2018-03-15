/**
## leetcode jump-game
### 题目
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.

For example:

A =[2,3,1,1,4], return true.

A =[3,2,1,0,4], return false.

### 思路
遍历过程中记录最远能到达的点，如果最后最远能到达的点不小于终点则说明能到达
<https://segmentfault.com/a/1190000003488956>

**/

bool canJump(int A[], int n) {
    int i = 0;
    int max = 0;//记录能到达的最远的点

    for(; i<n && i<=max; ++i){
        if(max<i+A[i]){
            max = i+A[i];
        }
    }

    return i==n;
}
