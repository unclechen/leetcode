#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *tail;

// 新树每个节点的右孩子指向(原树)先序遍历的下一个节点 
void traverse(TreeNode *root) {
	if (NULL == root) return;
	TreeNode* left = root->left;  
    TreeNode* right = root->right;  
	if (NULL == tail) {
		tail = root;
	}
	else {
		tail->right = root;
		tail->left = NULL;
		tail = root;
	}
	traverse(left);
	traverse(right);	
} 

// 思路：应该先序遍历，当前节点的左子结点置为右子节点，右子节点置为左子结点的右子节点 
void flatten(TreeNode *root) {
	if (NULL == root) return;
	traverse(root);
}


/* 非递归法，找到左子树最右下角的节点，该节点的右子树置为root->right，然后把root右子树置为root->left 
void flatten(TreeNode *root) {  
        if(root == NULL) return;  
    while(root){  
        if(root->left){  
            TreeNode *pre = root->left;  
            while(pre->right)  
                pre = pre->right;  
            pre->right = root->right;  
            root->right = root->left;  
            root->left = NULL;  
        }  
        root = root->right;  
    }  
    }
*/
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
	flatten(t1);
	printTree(t1);
	
	return 0; 
} 


