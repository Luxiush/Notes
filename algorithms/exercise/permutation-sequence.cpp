/*leetcode permutation-sequence*/
/*
题意：给定n(1<=n<=9)和k求数组{1,2...n}的第k个全排列
思路：http://www.cnblogs.com/grandyang/p/4358678.html

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;


    string getPermutation(int n, int k) {
        string res;
		vector<int> factorial(n,1);//保存阶乘结果
		string num(n, '1');
		for(int i=1; i<n; ++i) 
			factorial[i] = i*factorial[i-1];
		for(int i=0; i<n; ++i)
			num[i] += i;
		
		--k; //转化为数组下标
		int j;
		for(int i=n-1; i>=0; --i){
			j = k/factorial[i];
			k %= factorial[i];
			res.push_back(num[j]);
			num.erase(j,1);
		}
		
		return res;
    }



string Permutation(string str, int start){
	if(start>=str.length()-1){
		cout<< str<< endl;
		return str;
	} 
	
	char temp = '0';
	string str_old;
	string str_temp;
	for(int i=start; i<str.length(); ++i){
		str_old = str;
		
		//把第i个元素前移到str[start]
		str_temp = str[i];
		str_temp.append(str, start, i-start);
		str.replace(start, i-start+1, str_temp);

		Permutation(str,start+1);

		str = str_old;
	
	}
	
	return str;
}	

	
int main(){
	string str = "1234";

	Permutation(str, 0);
	
//	cout<< getPermutation(9,13)<< endl;
	
	return 0;
}
