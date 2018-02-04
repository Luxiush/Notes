/**
## 二叉树中和为某一值的路径
### 题目
> 输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
### 思路
递归.
注意空树的情况.
注意叶节点只需递归一次. 
**/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> > res;
        if(!root) return res;
        vector<int> tmp;
        _FindPath(root, expectNumber, res, tmp);
        return res;
    }
private:
    void _FindPath(TreeNode* r, int expectNumber, vector<vector<int> >& res, vector<int> tmp){
        if(!r){
            if(expectNumber==0){
                res.push_back(tmp);
            }
            return;
        }
        if(r->val > expectNumber) return ;
        
        tmp.push_back(r->val);
        _FindPath(r->left, expectNumber-r->val, res, tmp);
        if(r->right)    // 遇到叶节点时, 只需再往下递归一次即可. 
            _FindPath(r->right, expectNumber-r->val, res, tmp);
    }
};

/**
                10              
            /        \          
          5           12        
        /  \                    
       4    7                   
**/
int main(){
    TreeNode* r = new TreeNode(10);
    r->left = new TreeNode(5);
    r->right = new TreeNode(12);
    r->left->left = new TreeNode(4);
    r->left->right = new TreeNode(7);
    
    vector<vector<int> > res;
    Solution S;
    res = S.FindPath(r, 22);
    
    cout<< "res:"<< endl;
    for(int i=0; i<res.size(); ++i){
        for(int j=0; j<res[i].size(); ++j){
            cout<< res[i][j]<< " ";
        }
        cout<< endl;
    }
    cout<< "-----------"<< endl;
    
    return 0;
}