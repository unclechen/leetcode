// Maxinum Depth of Binary Tree 
#include <iostream>
#include <cmath>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
** 1、和最小深度不一样，最小深度不能直接递归比较左子树和右子树中最小的深度，因为当一个子树为空时，返回的大小是0 
** 因为min函数取出的会是那个null子树的深度，再+1返回。
** 2、而我们的叶子节点定义不是这样的，应该把非null的那个子树的深度取出来，再+1；
** 这道题就不用考虑这个了，因为null子树的深度不会被取出来，所以直接不用分出一个root的左右子树的各种非null情况。 
*/
int maxDepth(TreeNode *root) {
	if (NULL == root) return 0;
	if (NULL == root->left && NULL == root->right) {
		return 1;
	} 
	else {
		return max(maxDepth(root->left), maxDepth(root->right))+1;
	}
}
