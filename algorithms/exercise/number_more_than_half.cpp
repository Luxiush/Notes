/*
## 求数组中出现次数超过一半的数字
### 题目

### 思路
第n/2小数
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int len = numbers.size();
        int num = kth_min(numbers, 0, len, len/2);
        if(num==-1) return 0;
        int count = 0;
        for(int i=0; i<len; ++i){
            if(numbers[i]==num && ++count==len/2+1){
                return num;
            }
        }
        return 0;
    }

//private:
    int kth_min(vector<int>& v, int begin, int end, int k){ // begin <= i < end
        cout<< begin<< ","<< end<< "| ";
        for(int i=0; i<v.size(); ++i){
            cout<< v[i]<< " ";
        }
        cout<< endl;
        if(begin==end){
            if(begin==k) return v[k];
            
            return -1;
        }
        int i_sorted = begin;
        for(int i=begin+1; i<end; ++i){
            if(v[i]<=v[begin]){
                i_sorted += 1;
                _swap(v[i_sorted], v[i]);
            }
        }
        _swap(v[i_sorted], v[begin]);
        
        if(i_sorted == k) return v[k];
        else if(i_sorted < k)
            return kth_min(v, i_sorted+1, end, k);
        else 
            return kth_min(v, begin, i_sorted, k);
    }
    
    void _swap(int& a, int& b){
        /*
        a = a + b;
        b = a - b;
        a = a - b;
        *//*
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
        */
        
        int tmp = a;
        a = b;
        b = tmp;
        
    }
};

int main(){
    Solution S;
    int tmp[] = {1,2,3,2,2,2,5,4,2};
    int length = sizeof(tmp)/sizeof(int);
    vector<int> v;
    for(int i=0; i<length; ++i){
        v.push_back(tmp[i]);
    }
    
    int res = S.kth_min(v, 0, v.size(), 5);
    
    cout<< endl<< res<< endl;
    for(int i=0; i<v.size(); ++i){
        cout<< v[i]<< " ";
    }
    cout<< endl;
    
    return 0;
}

int test(){
    
    int a,b;
    while(cin>> a>> b){
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
        
        cout<< a<< " "<< b<< endl;
    }
    
    return 0;
}