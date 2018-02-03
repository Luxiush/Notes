/**
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

**/
    int numDistinct(string S, string T) {
        int dp[T.size() + 1][S.size() + 1];
        for (int i = 0; i <= S.size(); ++i) dp[0][i] = 1;
        for (int i = 1; i <= T.size(); ++i) dp[i][0] = 0;
        for (int i = 1; i <= T.size(); ++i) {
            for (int j = 1; j <= S.size(); ++j) {
                dp[i][j] = dp[i][j - 1] + (T[i - 1] == S[j - 1] ? dp[i - 1][j - 1] : 0);
            }
        }
        return dp[T.size()][S.size()];
    }
