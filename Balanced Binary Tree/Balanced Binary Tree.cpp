#include <iostream>
#include <cmath>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int getHeight(TreeNode *root) {
	if (NULL == root) return 0;
	int height = 1;
	int left = getHeight(root->left);
	int right = getHeight(root->right);
	if (left > right) {
		height += left;
	} 
	else {
		height += right;
	}
	
	return height;
}

bool isBalanced(TreeNode *root) {
	if (NULL == root) return true;
	int left = getHeight(root->left);
	int right = getHeight(root->right);
	if ( abs(left-right) > 1 )
		return false;
	else
		return isBalanced(root->left) && isBalanced(root->right);
}

int main() {
	// ²Ë¹·°æ½¨Á¢¶þ²æÊ÷ 
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t3 = new TreeNode(3);
	TreeNode* t4 = new TreeNode(4);
	TreeNode* t5 = new TreeNode(5);
	TreeNode* t6 = new TreeNode(6);
	t1->left = t2;
	t1->right = t5;
	t2->left = t3;
	t2->right = t4;
	t5->right = t6;
	
	if (isBalanced(t1)) {
		cout << "true" << endl; 
	}
	else {
		cout << "false" << endl; 
	} 
	
	return 0; 
} 
