/**
## 和为S的连续整数序列
### 题目
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!

### 思路
双指针问题:
if 和小于S: 大指针++
if 和大于S: 小指针++
**/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > res;
        if(sum<3) return res;
        int i_low = 1, i_high = 2, s = 3;
        while(i_low < i_high){
            // cout<< "[log]"<< i_low<< " "<< i_high<< " "<< s<< endl;
            if(s<sum){
                i_high ++;
                s += i_high;
            }
            else if(s>sum){
                s -= i_low;
                i_low ++;
            }
            else{
                vector<int> tmp;
                for(int i=i_low; i<=i_high; ++i){
                    tmp.push_back(i);
                }
                res.push_back(tmp);
                
                i_high ++;
                s += i_high;
            }
        }
        return res;
    }
};

int main(){
    Solution S;
    int s;
    while(cin>>s){
        vector<vector<int> > seq = S.FindContinuousSequence(s);
        for(int i=0; i<seq.size(); ++i){
            for(int j=0; j<seq[i].size(); ++j){
                cout<< seq[i][j]<< " ";
            }
            cout<< endl;
        }
        cout<< "-----------"<< endl;
    }
    return 0;
}