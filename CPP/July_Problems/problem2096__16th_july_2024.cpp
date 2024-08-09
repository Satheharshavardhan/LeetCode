#include <iostream>

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

string search(TreeNode *root, int val, string s)
{
    if (!root)
    {
        return "";
    }
    if (root->val == val)
    {
        return s;
    }
    string leftResult = search(root->left, val, s + "L");
    if (!leftResult.empty())
    {
        return leftResult;
    }
    string rightResult = search(root->right, val, s + "R");
    if (!rightResult.empty())
    {
        return rightResult;
    }
    return "";
}

string getDirections(TreeNode *root, int startValue, int destValue)
{
    string start = search(root, destValue, "");
    string end = search(root, destValue, "");
    int index = 0;
    while (index < start.length() && index < end.length() && start[index] == end[index])
    {
        index++;
    }
    start = start.substr(index);
    end = end.substr(index);
    if (start.empty())
    {
        return end;
    }
    else if (end.empty())
    {
        int i = 0;
        while (i < start.size())
        {
            start[i] = 'U';
            i += 1;
        }
        return start;
    }
    else
    {
        int i = 0;
        while (i < start.size())
        {
            start[i] = 'U';
            i += 1;
        }
        return start + end;
    }
}

int main()
{
    return 0;
}