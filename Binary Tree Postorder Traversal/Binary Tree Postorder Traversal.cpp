#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
二叉树的后序非递归方法遍历，难度复杂很多 
需要设置一个pre指针，表示前一个被访问的节点

思路：要保证根结点在左孩子和右孩子访问之后才能访问，
因此对于任一结点P，先将其入栈。如果P不存在左孩子和右孩子，则可以直接访问它；
或者P存在左孩子或者右孩子，但是其左孩子和右孩子都已被访问过了，则同样可以直接访问该结点。
若非上述两种情况，则将P的右孩子和左孩子依次入栈，这样就保证了每次取栈顶元素的时候，
左孩子在右孩子前面被访问，左孩子和右孩子都在根结点前面被访问。 
*/ 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> postorderTraversal(TreeNode *root) 
{
    vector<int> result; 
    //if (root == NULL)
    //   return NULL; 
    stack<TreeNode*> s;
    TreeNode *pre = NULL;
    if (root) 
        s.push(root);
    else
        return result;
    while (!s.empty())
    {
            TreeNode *p = s.top();
            if ( (p->left == NULL && p->right ==NULL) || (pre != NULL && (pre == p->left || pre == p->right)) )
            {
                 result.push_back(p->val);
                 s.pop();
                 pre = p;
            } 
            else//(p->left || p->right)
            {
                if (p->right)
                    s.push(p->right);
                if (p->left)
                    s.push(p->left);
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
    result = postorderTraversal(n1); 
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    
    system("pause");
    return 0;
}
