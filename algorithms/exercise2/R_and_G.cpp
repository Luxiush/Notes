/**
## 红R和绿G:
### 题目大意
有一个值为R或G的字符串, 现需要改变其中某些项的值使得每个R都比每个G距离最左侧近. 
问至少需要改变多少项的值.

### 思路 
* 题目可理解为:找到一个点将数组切分，使得左边全是R，右边全是G，并且改动数最小.
* 这无外乎有n+1中切法: 0:n, 1:n-1, ...., n:0.
可以分别用两个数组arr_R和arr_G统计到目前R和G的数量, 
对于每种分割, 将左边的所有G变为R, 右边的所有R变为G. 
所以, 颜色改变数 = 左边G的数量 + 右边R的数量
**/

#include <iostream>
#include <string>

using namespace std;

int main(){
	const int MAX_LEN = 55;
	int R_no[MAX_LEN];
	int G_no[MAX_LEN];
	int len = 0;
	
	for(int i=0; i<MAX_LEN; ++i){
		R_no[i] = 0;
		G_no[i] = 0;
	}
	
	string s_in;
	cin >> s_in;
	len = s_in.length();
	for(int i=0; i<len; ++i){
		if(s_in[i] == 'R'){
			if(i==0) R_no[i] = 1;
			else{
				R_no[i] = R_no[i-1]+1;
				G_no[i] = G_no[i-1];
			}
		}
		else if(s_in[i] == 'G'){
			if(i==0) G_no[i] = 1;
			else{
				G_no[i] = G_no[i-1]+1;
				R_no[i] = R_no[i-1];
			}
		}
	}
			
	int G_total = G_no[len-1];
	int R_total = R_no[len-1];
	
	// 全为R或全为G
	int res_min = (G_total<R_total)? G_total: R_total;
	
	int res = 0;
	for(int i=0; i<len; ++i){
		// 左边需要改动的数目为G的数量， 右边需要改动的为R的数量
		res = G_no[i] + R_total-R_no[i];	
		if(res < res_min)
			res_min = res;
	}
	
	cout << res_min<< endl;

	return 0;
}
