#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void printVector(vector<int> v){
	for(int i=0; i<v.size(); ++i)
		cout<< v[i]<< " ";
	cout<< endl;
}

// 求全排列
    void permute_rec(vector<int> &num, int start, vector< vector<int> > &res){
        if(start == num.size()-1){
//			printVector(num);
            res.push_back(num);
            return ;
        }
        vector<int> num_temp(num.size(),0);
        for(int i=start; i<num.size(); ++i){
            num_temp.assign(num.begin(), num.end());
			num_temp.erase(num_temp.begin()+i);
			num_temp.insert(num_temp.begin()+start, num[i]);
            
            permute_rec(num_temp, start+1, res);
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        vector< vector<int> > res;
        
        permute_rec(num, 0, res);
        
        return res;
    }
	

// 当输入数组里面有重复元素时，输出不同的全排列
    void permute_rec2(vector<int> &num, int start, vector< vector<int> > &res){
		static int rec_count = 0;
		
		++ rec_count;
		cout<< "rec_count: "<< rec_count<< ", start: "<< start<< ", num: "; printVector(num);
		
        if(start == num.size()-1){
//			printVector(num);
            res.push_back(num);
			
			-- rec_count;
			
            return ;
        }
        vector<int> num_temp(num.size(),0);
        for(int i=start; i<num.size(); ++i){
			cout<< "rec_count: "<< rec_count<< ", i: "<< i<< endl; 
			
			if(num[i]==num[start]&&i!=start)  	continue;
			if(i-1>start&&num[i]==num[i-1]) 	continue;	
			
			num_temp.assign(num.begin(), num.end());
			num_temp.erase(num_temp.begin()+i);
			num_temp.insert(num_temp.begin()+start, num[i]);
			permute_rec2(num_temp, start+1, res);
        }
		cout<< "end"<< endl<<endl;
		--rec_count;		
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
		vector< vector<int> > res;
		
		sort(num.begin(), num.end());
        
        permute_rec2(num, 0, res);
        
        return res;        
    }	
	
	
int main(){
	int n, temp;
	vector<int> in;
	vector< vector<int> > res;
	
	cin>> n;
	while(n--){
		cin>> temp;
		in.push_back(temp);
	}
	
//	res = permute(in);
	res = permuteUnique(in);
	for(int i=0; i<res.size(); ++i)
		printVector(res[i]);
	
	return 0;
}	