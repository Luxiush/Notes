/*leetcode binary-tree-level-order-traversal-ii*/
/*二叉树的层次遍历*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

    vector<vector<int> > levelOrderBottom(TreeNode *root) {
		vector< vector<int> > res;
		if(!root) return res;
		
		queue<TreeNode*> Q;
		Q.push(root);
		TreeNode* t;
		int size;
		while(!Q.empty()){
			vector<int> temp;
			size = Q.size();
			for(int i=0; i<size; ++i){
				t = Q.front();
				temp.push_back(t->val);
				Q.pop();
				if(t->left) Q.push(t->left);
				if(t-right) Q.push(t->right);
			}
			res.push_back(temp);
		}
		reverse(res.begin(), res.end());
		return res;
	}

    vector<vector<int> > levelOrderBottom_2(TreeNode *root) {
        vector< vector<int> >res;
		if(!root) return res;
		
        vector<TreeNode*> current;
        vector<TreeNode*> next;
        current.push_back(root);
        
        while(current.size()!=0){
            vector<int> value;
            for(int i=0; i<current.size(); ++i){
                if(current[i]->left)
                	next.push_back(current[i]->left);
                if(current[i]->right)
	                next.push_back(current[i]->right);
                value.push_back(current[i]->val);
            }
            
            res.insert(res.begin(), value);
            
            current.clear();
            current.assign(next.begin(), next.end());
            next.clear();
        }
        return res;
    }
	
	

int main(){
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(2);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	
	vector< vector<int> > res;
	res = levelOrderBottom(root);
	
	for(int i=0; i<res.size(); ++i){
		for(int j=0; j<res[i].size(); ++j){
			cout<< res[i][j]<< " ";
		}
		cout<< endl;
	}
	cout<< endl;

	return 0;
}