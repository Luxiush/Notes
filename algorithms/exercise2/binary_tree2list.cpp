/**
## 二叉搜索树转双向链表
### 题目
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
### 思路
#### v1
* 先对二叉树进行中序遍历, 得到相应序列, 再依次序列进行转换.

#### v2 递归

**/

#include <iostream>
#include <queue>
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
    TreeNode* Convert(TreeNode* r){
        if(!r) return 0;
        if(!r->left && !r->right) return r;
        
        vector<TreeNode*> inorder_seq;
        _InOrder(r, inorder_seq);
        
        for(int i = 0; i<inorder_seq.size()-1; ++i){
            inorder_seq[i]->right = inorder_seq[i+1];
            inorder_seq[i+1]->left = inorder_seq[i];
        }
        inorder_seq[0]->left = 0;
        inorder_seq[inorder_seq.size()-1]->right = 0;
        return inorder_seq[0];
    }
    
private: 
    void _InOrder(TreeNode* r, vector<TreeNode*>& res){
        if(!r) return;
        _InOrder(r->left, res);
        res.push_back(r);
        _InOrder(r->right,res);
    }
    
    void _Convert_rec(TreeNode* r, TreeNode* &pre){
        if(!r) return ;
        _Convert_rec(r->left, pre);     // 递归左子树求根节点的前驱节点
        
        if(pre)
            pre->right = r;
        r->left = pre;
        
        _Convert_rec(r->right, r);      // 以当前节点作为根节点, 递归右子树
    }
};


int main(){
    TreeNode* r = new TreeNode(4);
    r->left = new TreeNode(2);
    r->right = new TreeNode(6);
    r->left->left = new TreeNode(1);
    r->left->right = new TreeNode(3);
    r->right->left = new TreeNode(5);
    r->right->right = new TreeNode(7);
    
    Solution S;
    TreeNode* list_head = S.Convert(r);
    TreeNode* cur;
    for(cur=list_head; cur->right; cur=cur->right){
        cout<< cur->val<< " ";
    }
    cout<< cur->val<< endl;
    
    cout<< "-----------"<< endl;
    
    for(;cur; cur=cur->left){
        cout<< cur->val<< " ";
    }
    cout<< endl;
    
    return 0;
}















