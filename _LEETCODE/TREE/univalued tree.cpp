#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    bool helper(TreeNode *root, int val)
    {
        if (!root)
            return true;
        return root->val == val && helper(root->right, val) && helper(root->left, val);
    }

public:
    bool isUnivalTree(TreeNode *root)
    {
        return helper(root, root->val);
    }
};