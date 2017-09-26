/* 
## leetcode triangle
### 题目
给一个三角形矩阵，求从顶点到底边的最短路径

### [思路]( http://www.cnblogs.com/grandyang/p/4286274.html )
先复制三角形最后一行作为用来更新的一位数组。然后逐个遍历这个DP数组，对于每个数字，和它之后的元素比较选择较小的再加上上面一行相邻位置的元素做为新的元素，然后一层一层的向上扫描，整个过程和冒泡排序的原理差不多，最后最小的元素都冒到前面，第一个元素即为所求。

### 演示:  

2
3 4
6 5 7
4 1 8 3


11 1  8  3
9  10 8  3
7  6  10 3
4  1  8  3

*/

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int level = triangle.size();
		int max_len = triangle[level-1].size();
		
		int minSum[max_len];
		for(int i=0; i<max_len; ++i){
			minSum[i] = triangle[level-1][i];
		}
		
		int temp = 0;
		for(int l=level-2; l>=0; --l){
			for(int i=0; i<triangle[l].size(); ++i){
				temp = (minSum[i]<minSum[i+1])? minSum[i]: minSum[i+1]; 
				temp += triangle[l][i];
				minSum[i] = temp;
			}
		}
		return minSum[0];
    }
};

int main(){
	
	return 0;
}