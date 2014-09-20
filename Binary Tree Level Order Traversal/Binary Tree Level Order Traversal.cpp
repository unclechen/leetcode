// Binary Tree Level Order Traversal 
#include <iostream>
#include <cmath>
#include <vector>
#include <queue> 

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
vector<vector<int> > levelOrder(TreeNode *root) {
	vector<vector<int> > ret;
	vector<int> temp;
	queue <TreeNode* > q;
	if (NULL == root) return ret;
	q.push(root);
	int k = 1;
	int c = 0;
	while(!q.empty()) {
		TreeNode *p = q.front();
		if (p != NULL) {
			q.push(p->left);
			q.push(p->right); 
		}
		if ( c < pow(2, k)-1 ) { // 这种只适用于。。平衡二叉树（或者说满二叉树）。。主要是输入每一层的节点数量不对 
			if (p!=NULL) 
				temp.push_back(p->val); 
		} 
		else { 
			ret.push_back(temp); 
			temp.erase(temp.begin(), temp.end()); 
			k++; 
			if (p!=NULL) 
				temp.push_back(p->val); 
		} 
		c++; 
		q.pop();
	}
	
	return ret; 
}
*/
vector<vector<int> > levelOrder(TreeNode *root) {
	vector<vector<int> > ret;
	vector<int> temp;
	queue <TreeNode* > q;
	if (NULL == root) return ret;
	q.push(root);
	// 用两个队列，一个队列q保存当前每一层的节点，一层q2保存下一层节点，每次处理队列q
	// 并把当前层q的子节点保存节点到q2队列中，循环末尾把q2转移到q中 
	while(!q.empty()) { 
		queue <TreeNode* > q2; 
		while (!q.empty()) {
			TreeNode *p = q.front(); 
			if (p->left)  q2.push(p->left); 
			if (p->right) q2.push(p->right); 
			temp.push_back(p->val);
			q.pop();
		} 
		ret.push_back(temp);
		temp.clear();
		q = q2;
	}
	
	return ret; 
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
	
	// cout << pow(2, 9);
	vector<vector<int> > ret = levelOrder(t1); 
	// 3,2,4,1,5,6
	for (int i = 0; i < ret.size(); ++i) { 
		for (int j = 0; j < ret[i].size(); ++j) { 
			cout << ret[i][j] << "  "; 
		} 
		cout << endl; 
	} 
	cout << endl;
	
	return 0; 
} 
