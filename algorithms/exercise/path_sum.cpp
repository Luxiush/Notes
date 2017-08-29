#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void path(TreeNode* root, int sum, vector<int> p, vector< vector<int> >& res);

    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector< vector<int> > res;
        vector<int> p;
        path(root, sum, p, res);
        
        return res;
    }

    void path(TreeNode* root, int sum, vector<int> p, vector< vector<int> >& res){
        if(!root) return;
        p.push_back(root->val);
        sum -= root->val;
        if((!root->left)&&(!root->right)&&(!sum)){
            res.push_back(p);
            return ;
        }
        
        path(root->left, sum, p, res);
        path(root->right, sum, p, res);
 		
        return ;
    }

int main(){
	
	return 0;
}