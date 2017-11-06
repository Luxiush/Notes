/*
## [纸币组合问题]( http://www.cnblogs.com/python27/p/3303721.html )
### 描述: 现有1元, 5元, 10元, 20元, 50元, 100元6种面值的纸币. 给定一个数n,问有多少种组合方式.
### 思路:
* 题目等价于求方程: a + 5b + 10c + 20d + 50e + 100f = n 的解的个数. 
* 动态规划: (类似01背包)
当只有1元纸币时,n从1到n有多少种表示法,
当有1元和5元纸币时,n从1到n又有多少种表示法,
当有1元,5元和10元时...
...
由此可以维护一张表格dp, dp[i][j]表示用前i种纸币来表示j元的方法数.
当增加一种新的币值时,有两种情况:
1. 不加入此币值, 则 dp[i][j] = dp[i-1][j]
2. 加入此币值, 则 dp[j][j] = dp[i][j-coin[i]] (coin[i]表示第i种纸币的面值)
由此可以得到动态转移方程: dp[i][j] = dp[i-1][j] + dp[i][j-coin[i]] 
 
*/

#include <iostream> 

using namespace std;

int num(int n){
	const int COINTYPE = 6;
	const int MAX = 100000;
	int dp[COINTYPE][MAX];
	for(int i=0; i<COINTYPE; ++i){
		dp[i][0] = 1;
		for(int j=1; j<MAX; ++j){
			dp[i][j] = 0;
		}
	}
	
	
}

int main(){
	int n = 0;
	for(int i=0; i<MAX; ++i){
		A[i] = -1;
	}
	while(cin>>n){
		cout<< num(n)<< endl;
	}
}