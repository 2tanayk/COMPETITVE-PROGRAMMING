#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    vector<TreeNode *> children;
    TreeNode() : val(-1), children({}){};
    TreeNode(int x) : val(x), children({}){};
    TreeNode(int x, vector<TreeNode *> children) : val(x), children(children){};
};

class Generic_Tree
{
public:
    TreeNode *root;
    Generic_Tree(vector<int> tree)
    {
        stack<TreeNode *> s;
        for (auto val : tree)
        {
            if (val == -1)
                s.pop();
            else
            {
                TreeNode *temp = new TreeNode(val);
                if (s.empty())
                    this->root = temp;
                else
                    s.top()->children.push_back(temp);
                s.push(temp);
            }
        }
    }
    pair<int, int> ps_ans;
    void ps(TreeNode *root, int val, int &state = 0)
    {
        if (state == 0)
        {
            if (root->val == val)
                state = 1;
            else
                ps_ans.second = root->val;
        }
        else if (state == 1)
        {
        }
        for (auto child : root->children)
            ps(child, val, state);
    }
};

void print(TreeNode *root)
{
    if (!root)
        return;
    string level = to_string(root->val) + " -> ";
    for (auto child : root->children)
        level += to_string(child->val) + ", ";
    cout << level << endl;
    for (auto child : root->children)
        print(child);
}

int main()
{
    vector<int> tree = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 170, -1, -1, -1};
    Generic_Tree mtree(tree);

    return 0;
}
