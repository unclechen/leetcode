#include <iostream>
#include <cmath>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
* 获取所有叶子节点的深度，找到最小值 
* 叶子节点如何判断，对任何一个当前的root而言，左右子节点都为空时，才是个叶子节点。
* 左右子节点有任何一个时，说明该root都不是叶子节点。需要递归处理它。 
**/
int minDepth(TreeNode *root) {
	if (NULL == root) return 0;
	if (NULL == root->left && NULL == root->right) {
		return 1;
	}
	else if (NULL == root->left && NULL != root->right) {
		return minDepth(root->right)+1;
	}
	else if (NULL != root->left && NULL == root->right) {
		return minDepth(root->left)+1; 
	}
	else {
		return min(minDepth(root->left), minDepth(root->right))+1;
	}
}

int main() {
	// 菜狗版建立二叉树 
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
	
	cout << minDepth(t1) << endl; 
	
	return 0; 
} 
