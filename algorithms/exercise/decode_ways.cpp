/**
110
100			0
140

101
111
131
127			2

1			1
12			2
121			3
1212		5
12127		5

**/

#include <iostream>
#include <string>

using namespace std;

    int numDecodings(string s) {
        if(s.size()==0||s[0]=='0') return 0;
        if(s.size()==1) return (('0'<s[0]&&s[0]<='9')? 1: 0);
        int res = 0;	//res[n]
		int a=1; 		//res[n-2]
        int b=1;		//res[n-1]

        for(int i=1; i<s.size(); ++i){
            if(s[i]=='0'){
                if(s[i-1]=='1'||s[i-1]=='2'){
					b = 0;
				}
				else{
					a = 0;
				}
            }
			else if('0'<s[i]&&s[i]<'7'){
				if(s[i-1]!='1'&&s[i-1]!='2'){
					a = 0;
				}
			}
			else if(s[i]>'6'){
				a = 0;
			}

            res = a+b;
            a = b;
            b = res;
        }

        return res;
    }

int main(){
	string s;
	cin>> s;
	cout<< numDecodings(s)<< endl;

	return 0;
}
