#include <iostream>
#include <vector>

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

void get_postorder_traversal(TreeNode *root, vector<int> &order)
{
    if (root)
    {
        get_postorder_traversal(root->left, order);
        get_postorder_traversal(root->right, order);
        order.push_back(root->val);
    }
}

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> order;
    get_postorder_traversal(root, order);
    return order;
}

int main()
{
    return 0;
}