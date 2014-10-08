// Unique Binary Search Trees II
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//
bool isValid (TreeNode * root, int left_bound, int right_bound) {
	if (NULL == root) return true;
	if (root->val <= left_bound || root->val >= right_bound) return false; 
	
	return isValid(root->left, left_bound, root->val) && isValid(root->right, root->val, right_bound);
}

// 思路有错，应该控制边界 
bool isValidBST(TreeNode *root) {
	if (NULL == root) return true;
	
	return isValid(root, INT_MIN, INT_MAX);
}

int main() {
	TreeNode* root = new TreeNode(1);
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node3 = new TreeNode(3);
	TreeNode* node4 = new TreeNode(4);
	TreeNode* node5 = new TreeNode(5);
	
	root->left = node2;
	root->right = node3;
	node3->left = node4;
	node4->right = node5;
	
	if (isValidBST) {
		cout << "true" << endl;
	}
	else {
		cout << false << endl;
	}
	
	return 0; 
}
