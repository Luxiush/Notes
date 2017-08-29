/*leetcode restore-ip-addresses*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isValid(string s);
void restore_rec(string s, string out, int seg_num, vector<string>& res);
vector<string> restoreIpAddresses(string s);


    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        restore_rec(s,"",4, res);
        return res;
    }

    void restore_rec(string s, string out, int seg_num, vector<string>& res){
        if(seg_num==0){
            if(s.size()==0)
	            res.push_back(out);
            return;
        }
        string temp;
        for(int i=1; i<=s.size()&&i<=3; ++i){
			temp = out;
            if(isValid(s.substr(0,i))){
                if(temp!="")temp.append(".");
                temp.append(s.substr(0,i));
                restore_rec(s.substr(i,s.size()-i), temp, seg_num-1, res);
            }
        }
        return;
    }
  	
    bool isValid(string s){
        if(s[0]=='0'&&s.size()==1) return true;
        if(s[0]=='0') return false;
        if(atoi(s.c_str())<=255) return true;
        
        return false;
    }

int main(){
	string s;
	vector<string> res;
	cin>> s;
		
	res = restoreIpAddresses(s);
	
	for(int i=0; i<res.size(); ++i){
		cout<< res[i]<< endl;
	}
		
	return 0;
}