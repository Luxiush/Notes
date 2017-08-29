/*
 后缀表达式求值
 ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 
 思路：从左往右遍历，操作数入栈，碰到操作符时取出栈顶两个元素进行操作结果入栈，继续遍历
       注意 “-” 和 “/” 的操作数的顺序
*/
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int ReversePolish(vector<string> &tokens){
        stack<int> S;
        int temp1 = 0, temp2 = 0;
        for(int i=0; i<tokens.size(); ++i){
			if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
				temp2 = S.top(); S.pop();
				temp1 = S.top(); S.pop();
				if(tokens[i]=="+")
				   S.push(temp1+temp2);
				else if(tokens[i]=="-")
				   S.push(temp1-temp2);
				else if(tokens[i]=="*")
				   S.push(temp1*temp2);
				else if(tokens[i]=="/")
				   S.push(temp1/temp2);
			}
			else{
			   S.push(atoi(tokens[i].c_str()));
			}
        }
        return S.top();	
}

int main(){
	vector<string> tokens;
	string t;
	while(cin>>t){
		if(t=="z") break;
		tokens.push_back(t);
	}
	
	for(int i=0; i<tokens.size(); ++i){
		cout<< atoi(tokens[i].c_str())<< endl;
	}
	
	cout<< "res: "<< ReversePolish(tokens)<< endl;
	
	return 0;
}

