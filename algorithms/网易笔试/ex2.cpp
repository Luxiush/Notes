/*
x % 4 == 0
x % 4 != 0 :
   x%2 == 0
   x%2 == 1
*/
#include <iostream> 

using namespace std;

int main(){
    int test_case = 0;
    cin >> test_case;
    while(test_case --){
		int arr_len = 0;
		int tmp = 0;
        
        int half_len = 0;
        int n4 = 0;		//ģ4Ϊ0������
        int n2 = 0;		//ģ2Ϊ0������
        int n1 = 0;		//ģ2Ϊ1������
        
        cin >> arr_len;
        half_len = arr_len / 2;
        for(int i=0; i<arr_len; ++i){
            cin >> tmp;
            if(tmp%4==0){
                n4 += 1;
            }
            else if(temp%2==0){
                n2 += 1;
            }
            else{
                n1 += 1;
            }
        }
        
		if(n4>=n1){
			cout<< "Yes"<< endl;
		}
		else{
			if(n4==n1-1 && n2==0){
				cout<< "Yes"<< endl;
			}
			else{
				cout<< "No"<< endl;
			}
		}
    }
    return 0;
}