// Unique Binary Search Trees II
#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode *> generate(int left, int right) {
	vector<TreeNode *> ret;
	if (left > right) {
		ret.push_back(NULL);
		return ret;
	}
	for (int i = left; i <= right; ++i ) {
		vector<TreeNode *> left_subtrees = generate(left, i - 1);
		vector<TreeNode *> right_subtrees = generate(i + 1, right);
		for (int m = 0; m < left_subtrees.size(); ++m) {
			for (int n = 0; n < right_subtrees.size(); ++n) {
				TreeNode *t = new TreeNode(i);
				t->left = left_subtrees[m];
				t->right = right_subtrees[n];
				ret.push_back(t);
			}
		} 
	}
	
	return ret;
}

vector<TreeNode *> generateTrees(int n) {
	return generate(1, n);
}

int main() {
	
	
	return 0;
}
