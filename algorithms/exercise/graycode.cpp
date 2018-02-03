/**
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

**/

#include <iostream>
#include <vector>

using namespace std;

    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        if(n==0) return res;
        res.push_back(1);

        for(int i=1; i<n; ++i){
            for(int j=res.size()-1; j>=0; --j){
                res.push_back((1<<i)+res[j]);
            }
        }

        return res;
    }

int main(){
	int n;
	cin>> n;
	vector<int> res;
	res = grayCode(n);
	for(int i=0; i<res.size(); ++i){
		cout<< res[i]<< " ";
	}
	cout<< endl;

	return 0;
}
