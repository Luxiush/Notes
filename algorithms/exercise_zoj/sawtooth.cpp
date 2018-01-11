/*
## HDU 5047 Sawtooth 

### 题目
- 求n个'M'形最多能把平面分成多少块

### 思路
<https://www.2cto.com/kf/201409/338950.html>
- 找规律, 推出公式: 8*n*n -7*n + 1 (0<=n<=10^12)
- 考虑到n*n会很大, 需要用借鉴大数运算, 注意中间结果溢出. 

*/

#include <iostream>

using namespace std;

typedef long long ll;
const ll BASE = 1000000; // 10^6

void cal(ll n, ll &r_h, ll &r_l){
	ll m_h = (8*n - 7) / BASE;
	ll m_l = (8*n - 7) % BASE;

	ll r_tmp = n * m_l + 1;

	r_l = r_tmp % BASE;
	r_h = n*m_h + r_tmp/BASE;
}

int main(){
	int t;
	ll n;
	ll r_h, r_l;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i){
		scanf("%I64d", &n);
		// cout << "---" << 8*n*n - 7*n + 1 << endl;
		cal(n, r_h, r_l);
		cout << "Case #" << i << ": ";
		if (r_h) printf("%I64d%06I64d\n", r_h, r_l);		
		else printf("%I64d\n", r_l);
	}

	return 0;
}

