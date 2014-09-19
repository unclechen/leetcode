#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int max_sum;
int DFS(TreeNode *root) {
	if (NULL == root) return 0;
	int sum = root->val;
	int left = DFS(root->left);
	int right = DFS(root->right);
	if (left > 0) {
		sum += left;
	}
	if (right > 0) {
		sum += right;
	}
	max_sum = max(max_sum, sum);
	return (max(left, right) > 0 ? max(left, right) + root->val : root->val);
}
//  
int maxPathSum(TreeNode *root) {
	max_sum = INT_MIN;
	DFS(root);
	return max_sum;
}

// 先序遍历，打印 
void printTree(TreeNode *root) {
	if (NULL != root) {
		cout << root->val << " ";
		printTree(root->left);
		printTree(root->right); 
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
	printTree(t1);
	cout << endl;
	
	cout << maxPathSum(t1) << endl; 
	
	return 0; 
} 
