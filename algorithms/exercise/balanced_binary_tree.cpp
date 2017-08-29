/*leetcode balanced-binary-tree*/
/*判断一棵二叉树是否是平衡二叉树*/
/*基于后续遍历，每经过一个节点时如果其左右两子树的高度差超过1则返回false，否则求其高度继续遍历，结束时返回true*/


bool isBalanced(TreeNode *root) {
	if(!root) return true;
	if(isBalanced_rec(root)==-1) return false;
	return true;
}
	
int isBalanced_rec(TreeNode* root){
	if(!root) return 0;
	int l = isBalanced_rec(root->left);
	if(l==-1) return -1;
	int r = isBalanced_rec(root->right);
	if(r==-1) return -1;
	if(r-l>1 || l-r>1) return -1;
	return (l>r)? l+1: r+1;	
}

	