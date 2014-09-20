// Binary Tree Inorder Traversal 
#include <iostream>
#include <cmath>
#include <vector> 
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode *root) {
	vector<int> ret;
	if (NULL == root) return ret;
	stack<TreeNode*> s;
	s.push(root);
	while(!s.empty()) {
		TreeNode *p = s.top();
		if (p->left != NULL) {
			s.push(p->left);
			p->left = NULL;
		}
		else {
			ret.push_back(p->val);
			s.pop();
			if (p->right != NULL){
				s.push(p->right);
			}
		}
	}
	
	return ret; 
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
	
	vector<int> ret = inorderTraversal(t1);
	// 3,2,4,1,5,6
	for (int i = 0; i < ret.size(); ++i) {
		cout << ret[i] << ", ";
	}
	cout << endl;
	
	return 0; 
} 
