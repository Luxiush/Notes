/**
## 二叉树的各种遍历

**/
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

void preOrder(TreeNode* root, vector<int>& res){
	if(!root) return;
	stack<TreeNode*> S;
	TreeNode* temp;

	S.push(root);
	while(!S.empty()){
		temp = S.top();
		S.pop();
		res.push_back(temp->val);
		if(temp->right)
			S.push(temp->right);
		if(temp->left)
			S.push(temp->left);
	}
}

void postOrder(TreeNode* root, vector<int>& res){
	if(!root) return;
	stack< pair<TreeNode*, bool> > S;
	TreeNode* temp;
	bool visited;

	S.push(make_pair(root, false));
	while(!S.empty()){
		temp = S.top().first;
		visited = S.top().second;
		if(!visited){
			S.top().second = true;
			if(temp->right)
				S.push(make_pair(temp->right, false));
			if(temp->left)
				S.push(make_pair(temp->left, false));
		}
		else{
			res.push_back(temp->val);
			S.pop();
		}
	}
}

void inOrder(TreeNode* root, vector<int>& res){
	if(!root) return;
	stack< pair<TreeNode*, bool> > S;
	TreeNode* temp;
	bool visited;

	S.push(make_pair(root, false));
	while(!S.empty()){
		temp = S.top().first;
		visited = S.top().second;

		if(!visited){
			S.top().second = true;
			if(temp->left)
				S.push(make_pair(temp->left, false));
		}
		else{
			res.push_back(temp->val);
			S.pop();
			if(temp->right)
				S.push(make_pair(temp->right, false));
		}
	}
}

/*
     3
    / \
  9     20
 / \   / \
1   2 15  7
*/

int main(){
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(2);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	vector<int> res;
//	preOrder(root, res);
//	postOrder(root, res);
	inOrder(root, res);

	for(int i=0; i<res.size(); ++i){
		cout<< res[i]<< " ";
	}
	cout<< endl;

	return 0;
}
