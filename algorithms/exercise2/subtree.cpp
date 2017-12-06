/*
## 数的子结构
### 题目
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
*/

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) 
        :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 判断r2是不是r1的子结构
    bool HasSubtree(TreeNode* r1, TreeNode* r2){
        if(!r1 || !r2) return false;
        queue<TreeNode*> Q;
        Q.push(r1);
        TreeNode* temp = 0;
        while(!Q.empty()){
            temp = Q.front();
            Q.pop();

            if(temp->val == r2->val && _TreeEqual(temp, r2)){
                return true;
            }
            
            if(temp->left) Q.push(temp->left);
            if(temp->right) Q.push(temp->right);
        }
        cout<< endl;
        return false;
    }
    
    // 递归版
    bool HasSubtree2(TreeNode* r1, TreeNode* r2){
        if(!r1 || !r2) return false;
        return _TreeEqual(r1, r2) ||
               HasSubtree2(r1->left, r2) ||
               HasSubtree2(r1->right, r2);
    }

public:
    bool _TreeEqual(TreeNode* r1, TreeNode* r2){
        if(!r2) return true;
        if(!r1) return false;
        
        if(r1->val != r2->val) return false;
        return (_TreeEqual(r1->left, r2->left) && _TreeEqual(r1->right, r2->right)) || 
               (_TreeEqual(r1->left, r2->right) && _TreeEqual(r1->right, r2->left));
        
    }
};


int main(){
    TreeNode* r1 = new TreeNode(8);     //                       8                 
    r1->left = new TreeNode(8);         //                  /         \             
    r1->right = new TreeNode(7);        //               8               7          
    r1->left->left = new TreeNode(9);   //            /     \                       
    r1->left->right = new TreeNode(2);  //         9         2                      
    r1->left->right->left = new TreeNode(4); //             / \                     
    r1->left->right->right = new TreeNode(7); //           4   7                    
    
    /*
    r1->left = new TreeNode(2);
    r1->right = new TreeNode(9);
    r1->left->left = new TreeNode(7);
    */
    TreeNode* r2 = new TreeNode(8);     //             8                            
    r2->left = new TreeNode(2);         //            / \                           
    r2->right = new TreeNode(9);        //           2   9                          
    
    Solution S;
    cout<< S.HasSubtree(r1, r2)<< endl;
    
    return 0;
}

