 
---
array_min_number.cpp
## 把数组排成最小的数
### 题目
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

### 思路
* 重新定义比较运算:
1. ab < ba ==> a < b
2. ab > ba ==> a > b
3. ab == ba ==> a == b

 
---
balanced_binary_tree.cpp
## leetcode balanced-binary-tree
## 题目:
判断一棵二叉树是否是平衡二叉树

## 思路
基于后续遍历，每经过一个节点时如果其左右两子树的高度差超过1则返回false，否则求其高度继续遍历，结束时返回true

 
---
binary_tree_level_traversal.cpp
## leetcode binary-tree-level-order-traversal-ii
### 思路
二叉树的层次遍历

 
---
binary_tree_traversal.cpp
## 二叉树的各种遍历

 
---
candy.cpp
## leetcode candy
### 题意
N个孩子站成一排，每个孩子有一个评分，为每个孩子分配糖果（每个孩子至少有一个），要求评分高的孩子得到的糖果要多余他的邻居.
求:
 所需的最少糖果数量所需的最少糖果数量.

### 思路
<http://bookshadow.com/weblog/2015/08/06/leetcode-candy/>

 
---
decode_ways.cpp
110
100			0
140

101
111
131
127			2

1			1
12			2
121			3
1212		5
12127		5

 
---
distinct-subsequences.cpp
## leetcode distinct-subsequences
### 题意
给定字符串S、T， 求S中有几个子串为T

例：
	S = "rabbbit",  T = "rabbit",  numDistinct(S,T) == 3

### 思路
动态规划 <http://www.cnblogs.com/grandyang/p/4294105.html>
- 找递推式：
```
	  Ø r a b b b i t
	Ø 1 1 1 1 1 1 1 1
	r 0 1 1 1 1 1 1 1
	a 0 0 1 1 1 1 1 1
	b 0 0 0 1 2 3 3 3
	b 0 0 0 0 1 3 3 3
	i 0 0 0 0 0 0 3 3
	t 0 0 0 0 0 0 0 3
```
- 由上表不难发现
1. 当S[j]==T[i]时，dp[i][j] = dp[i][j-1]+dp[i-1][j-1];
2. 当S[j]!=T[i]时，dp[i][j] = dp[i][j-1];

 
---
gas-sation.cpp
## leetcode gas-station
### 题目:
> There are N gas stations along a circular route, where the amount of gas at station i is gas[i].You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

> Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

> Note: The solution is guaranteed to be unique.

### (思路)[http://blog.csdn.net/kenden23/article/details/14106137]
#### 两个结论
1. 如果所有油站的油量小于所有里程的耗油量那么肯定无法走完全程
2. 如果从0到i的剩余油量小于0，则起点一定位于i之后(>=i)

#### 思路：
* 当前起点j从0开始一个一个地试，如果走到第i个站时剩余油量小于0则说明j不是要找的起点，将j移到下一个站重复以上过程。
* 由于**结论2**所以在走到第i个站油量小于0时可以直接将j移到i+1，从而加速循环
 
---
graycode.cpp
##leetcode gray-code
### 题目
给定n输出n bits的gray码串
- gray code：相邻两个数之间只有一个bit是不同的， 如：
```
1: 0 1
2: 00 01 11 10
3: 000 001 011 010 110 111 101 100
4: 0000 0001 0011 0010 00110 0111 0101 0100 1100 1101 ...
```

### 思路
```
gray(1) = 0, 1
gray(n) = 0,gray(n-1) + 1,rev(gray(n-1))
```

 
---
hdu4582.cpp
### HDU4582
<http://blog.csdn.net/sd_invol/article/details/9963741>

 
---
jump-game.cpp
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

 
---
jump-game-ii.cpp
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

 
---
largest_rectangle.cpp
## leetcode: largest-rectangle-in-histogram
### 题目
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

### 思路
#### v1
遍历数组，每找到一个局部峰值，然后向前遍历所有的值，算出共同的矩形面积，每次对比保留最大值

#### v2
维护一个栈，用来保存递增序列，相当于上面那种方法的找局部峰值，
当当前值小于栈顶值时，取出栈顶元素，然后计算当前矩形面积，
然后再对比当前值和新的栈顶值大小，
若还是栈顶值大，则再取出栈顶，算此时共同矩形区域面积，
照此类推，可得最大矩形

 
---
longest_valid_parentheses.cpp
## leetcode longest-valid-parentheses
### 题目
给一个仅包含'('和')'的字符串，求其左右括号相匹配的最长子串的长度

### 思路
去掉字符串中合法的序列，得到一个断点序列求各个断点之间的最长距离

*/

    int longestValidParentheses(string s) {
        stack<int> S;
        for(int i=0; i<s.size(); ++i){
            if(!S.empty()&&s[S.top()]=='('&&s[i]==')'){
                S.pop();
            }
            else{
                S.push(i);
            }
        }
        int last = s.size();
        int res = 0;
        while(!S.empty()){
            if(last-S.top()-1>res)
                res = last-S.top()-1;
            last = S.top();
            S.pop();
        }
        if(res<last-(-1)-1) res = last;

        return res;
    }
 
---
max-subarray.cpp
## leetcode maximum-subarray
### 题目
求一个数组的最大子数组

### 思路
#### v1 贪心, DP
```
max[i] = a[0] + a[1] + ... + a[i]
max[i+1] = max[i] + a[i+1], if max[i] + a[i+1] > 0
         = 0, otherwise
```

#### v2 分治
```
left_sum = 左半边子数组的最大和
right_sum = 右半边...
cross_sum = 跨越中点的子数组的最大和
max_sum = max(left_sum, right_sum, cross_sum)
```

 
---
num2str.cpp
## 密码破译(2017小米后台笔试题)
### 题目
* Description: 我们来做一个简单的密码破译游戏。破译的规则很简单，将数字转换为字母，1转化为a，2转化为b，依此类推，26转化为z。现在输入的密码是一串数字，输出的破译结果是该数字串通过转换规则所能产生的所有字符串。
* Input: 多行数据，每行为一个数字串。
* Output: 多行数据，每行对应输出通过数字串破译得到的所有字符串，并按照字符串顺序排列，字符串之间用单个空格分隔。每行开头和结尾不允许有多余的空格。

 
---
number_more_than_half.cpp
 
---
palindrome-partition-ii.cpp
## leetcode palindrome-partition-ii
### 题目
给定字符串，求最少的回文子串数量

### 思路 <https://discuss.leetcode.com/topic/2840/my-solution-does-not-need-a-table-for-palindrome-is-it-right-it-uses-only-o-n-space/2>

 
---
path_sum.cpp
 
---
permutation.cpp
 
---
permutation-sequence.cpp
 
---
pow.cpp
 
---
restore_ip.cpp
 
---
reverse_polish.cpp
 
---
sqrt.cpp
 
---
triangle.cpp
