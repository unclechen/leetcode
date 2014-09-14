#include <iostream>

using namespace std;

// 二叉排序树的重建,题目里说了只有两个节点需要被交换，那么问题就在于找出这两个节点来 
// 思路：前序/中序/后序遍历二叉树，比较当前节点，和左子节点，右子节点的值
// 当左边出现错误时，left=1;右边出现时，right=1；然后看若left和right都为1，则交换左右子结点
// 否则，当left=1时，交换当前节点和左子结点 ；当right=1时，交换当前节点和右子节点 
// 我采用的是前序遍历法，
// ****我这种面向过程，顺序的逻辑思维方式没有办法解决很多问题**** 

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void traversalTree(TreeNode *root) {
	if (NULL == root) return;
	int left = 0, right = 0;
	if (NULL != root->left) {
		if (root->left->val > root->val) {
			left = 1;
		}
	}
	if (NULL != root->right) {
		if (root->right->val < root->val) {
			right = 1;
		}
	}
	if (left == 1 && right == 1) {
		int temp = root->left->val;
		root->left->val = root->right->val;
		root->right->val = temp;
	}
	if (left == 1 && right != 1) {
		int temp = root->val;
		root->val = root->left->val;
		root->left->val = temp;
	}
	if (left != 1 && right == 1) {
		int temp = root->val;
		root->val = root->right->val;
		root->right->val = temp;
	}
	if (root->left != NULL)
		traversalTree(root->left);
	if (root->right != NULL)
		traversalTree(root->right);
}

void recoverTree(TreeNode *root) {
	if (NULL == root) return;
	traversalTree(root);
}
// 上面的理解是错的
 
// 中序遍历，打印 
void printTree(TreeNode *root) {
	if (NULL != root) {
		printTree(root->left);
		cout << root->val << " ";
		printTree(root->right); 
	}
}
// 标准answer，中序遍历排序二叉树时，输出的序列是递增的 
// 提示： 
// 先看一个递增序列：1 2 3 4 5 6 7.
// 交换4和6：1 2 3 6 5 4 7
// 注意，6是第一个大于后一个元素的（6 > 5， 5 > 4），4是最后一个小于前一个元素的（5 < 6，4 < 5）。
TreeNode *node1, *node2;  
TreeNode *pre;  
      
void traverse(TreeNode *root) {  
    if (root == NULL) {  
        return;  
    }      
    traverse(root->left);  
    if (pre != NULL && pre->val > root->val) {  
        node2 = root;  
        if (node1 == NULL) {  
            node1 = pre;  
        }  
    }  
    pre = root;  
    traverse(root->right);  
}
void recoverTree2(TreeNode *root) {  
    // Start typing your C/C++ solution below  
    // DO NOT write int main() function  
    node1 = node2 = NULL;  
    pre = NULL;  
    traverse(root);          
    node1->val ^= node2->val;  
    node2->val ^= node1->val;  
    node1->val ^= node2->val;  
} 
//

int main() {
	// 菜狗版建立二叉树 
	TreeNode* t1 = new TreeNode(1);
	TreeNode* t2 = new TreeNode(2);
	TreeNode* t3 = new TreeNode(3);
	TreeNode* t4 = new TreeNode(4);
	TreeNode* t5 = new TreeNode(5);
	t1->left = t2;
	t1->right = t3;
	t3->left = t4;
	t4->right = t5;
	printTree(t1);
	cout << endl;
	// 调整错误的节点，重建二叉排序树
	recoverTree2(t1);
	printTree(t1);
	
	return 0; 
} 
