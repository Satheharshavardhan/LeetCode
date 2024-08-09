#include <iostream>
#include <vector>
#include <unordered_map>

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

TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
{
    unordered_map<int, TreeNode *> nodes;
    unordered_map<int, bool> hasParent;

    for (const auto &desc : descriptions)
    {
        int parentVal = desc[0], childVal = desc[1], isLeft = desc[2];
        if (nodes.find(parentVal) == nodes.end())
        {
            nodes[parentVal] = new TreeNode(parentVal);
        }
        if (nodes.find(childVal) == nodes.end())
        {
            nodes[childVal] = new TreeNode(childVal);
        }
        if (isLeft)
        {
            nodes[parentVal]->left = nodes[childVal];
        }
        else
        {
            nodes[parentVal]->right = nodes[childVal];
        }
        hasParent[childVal] = true;
    }

    TreeNode *root = nullptr;
    for (const auto &node : nodes)
    {
        if (hasParent.find(node.first) == hasParent.end())
        {
            root = node.second;
            break;
        }
    }

    return root;
}

int main()
{
    return 0;
}