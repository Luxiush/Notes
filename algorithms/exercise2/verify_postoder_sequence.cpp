/*
## 二叉搜索树的后序遍历序列
### Description
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
### Solution
* 根据`二叉搜索树`的定义可知, 一个二叉搜索树的后序遍历结果应该是前半段(左子树节点)都小于根节点,而后半段(右子树节点)都大于根节点. 因此对于给定序列只要是验证以上特征,然后再递归对其左右子数组验证即可.
* 递归过程中需要注意只存在左子树和只存在右子树的特殊情况. 
*/

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(!sequence.size()) return false;
        return _VerifyRec(sequence, 0, sequence.size()-1);
    }
    
private:
    bool _VerifyRec(vector<int>& sequence, int begin, int end){
        if(begin >= end) return true;
        
        int root = sequence[end];
        int right_start = -1;
        for(int i=begin; i<end; ++i){
            if(sequence[i]>root){
                right_start = i;
                break;
            }
        }
        
        if(right_start == -1){ // 没有右子树
            return _VerifyRec(sequence, begin, end-1);
        }
        
        for(int i=right_start; i<end; ++i){
            if(sequence[i]<root) return false;
        }
        if(right_start == begin){ // 没有左子树
            return _VerifyRec(sequence, begin, end-1);
        }
        return _VerifyRec(sequence, begin, right_start-1) && _VerifyRec(sequence, right_start, end-1);
    }
};


int main(){
    
    return 0;
}