/*leetcode palindrome-partition-ii*/
/*给定字符串，求最少的回文子串数量*/
/*https://discuss.leetcode.com/topic/2840/my-solution-does-not-need-a-table-for-palindrome-is-it-right-it-uses-only-o-n-space/2*/

	int minCut(string s){
		int n = s.size();
		vector<int> mincut(n+1, 0);
		//初始假设每个字符单独构成一个回文串
		for(int i=0; i<=n; ++i)
			mincut[i] = i-1;
		
		for(int i=0; i<n; ++i){
			//回文串长度为奇数
			for(int j=0; (i-j)>=0 && (i+j)<n && s[i-j]==s[i+j]; ++j){
				if(mincut[i+j+1]>1+mincut[i-j])
					mincut[i+j+1] = 1+mincut[i-j];
			}
			
			//回文串长度为偶数
			for(int j=1; (i-j+1)>=0 && (i+j)<n && s[i-j+1]==s[i+j]; ++j){
				if(mincut[i+j+1]>1+mincut[i-j+1])
					mincut[i+j+1] = 1+mincut[i-j+1];
			}
		}
		return mincut[n];
	}