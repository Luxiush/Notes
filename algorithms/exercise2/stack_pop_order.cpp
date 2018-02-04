/**
## 栈的压入, 弹出序列
### 题目
> 输入两个整数序列，第一个序列(A)表示栈的压入顺序，请判断第二个序列(B)是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4，5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

### 思路 
借助一个辅助栈, 依次将A序列入栈, 如果碰到与B序列的第一个相等的则弹栈并将B序列指针后移直到不相等. 

**/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> S;
        int i_pop = 0;
        for(int i=0; i<pushV.size(); ++i){
            S.push(pushV[i]);
            while(!S.empty() && S.top()==popV[i_pop]){
                S.pop();
                i_pop += 1;
            }
        }
        
        if(S.empty()) 
            return true;
        return false;
    }
};

int main(){
    vector<int> pushV;
    vector<int> popV;
    int temp = 0;
    
    cout<< "input pushV"<< endl;
    while(cin>> temp){
        if(temp==-1) break;
        pushV.push_back(temp);
    }
    
    cout<< "input popV"<< endl;
    while(cin>> temp){
        if(temp==-1) break;
        popV.push_back(temp);
    }
    
    cout<< "aaaaaaa"<< endl;
    Solution S;
    cout<< S.IsPopOrder(pushV, popV)<< endl;
    
    return 0;
}