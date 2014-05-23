#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std; 
/*
二叉树的先序非递归方法遍历，没想到一把就过了。。
算法是仿照王道上的中序非递归方法遍历来做的
但是后序非递归遍历貌似有一定的复杂度！！ 
*/ 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
vector<int> preorderTraversal(TreeNode *root) 
{
    //if (root == NULL)
    //    return NULL;
    vector<int> result; 
    stack<TreeNode*> s;
    TreeNode *p = root;
    while (p || !s.empty())
    {
        if (p)
        {
            result.push_back(p->val);
            s.push(p);
            p = p->left;
        }
        else 
        {
            p = s.top();
            //visit(p)如果是中序非递归遍历的话，前面的访问操作就是放在这里的 
            s.pop();
            p = p->right; 
        }     
    }
    return result;
}

int main()
{
    vector<int> result;
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    n1->right = n2;
    n2->left = n3;
    result = preorderTraversal(n1); 
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    
    system("pause");
    return 0;
}
