/*
## 密码破译(2017小米后台笔试题)
### 题目
* Description: 我们来做一个简单的密码破译游戏。破译的规则很简单，将数字转换为字母，1转化为a，2转化为b，依此类推，26转化为z。现在输入的密码是一串数字，输出的破译结果是该数字串通过转换规则所能产生的所有字符串。
* Input: 多行数据，每行为一个数字串。
* Output: 多行数据，每行对应输出通过数字串破译得到的所有字符串，并按照字符串顺序排列，字符串之间用单个空格分隔。每行开头和结尾不允许有多余的空格。

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;


void decrypt(string str_in, string res_tmp, vector<string>& res){
	if(str_in.length() < 1){
		res.push_back(res_tmp);
		return;
	}
	if(str_in[0]=='0') return;
	int num = str_in[0]-'0' - 1;
	string res_tmp1(res_tmp);
	res_tmp1 += 'a'+num;
	decrypt(str_in.substr(1,str_in.length()-1), res_tmp1, res);
	
	if(str_in.length()>=2){
		int num2 = (str_in[0]-'0')*10 + str_in[1]-'0' -1;
		if(num2 < 26){
			res_tmp += 'a'+num2;
			decrypt(str_in.substr(2, str_in.length()-2), res_tmp, res);
		}
	}
	return;
}


int main(){
	string str_in;
	vector<string> res;
	
	while(cin >> str_in){
		decrypt(str_in, string(""), res);
		for(int i=0; i<res.size(); ++i){
			cout<< res[i]<< endl;
		}
		cout<< "------"<< endl;
		res.clear();
	}
}

