#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool check_Path(ListNode *head, TreeNode *root)
{
    if (head == nullptr)
    {
        return true;
    }
    if (root == nullptr)
    {
        return false;
    }
    if (head->val != root->val)
    {
        return false;
    }
    return check_Path(head->next, root->left) || check_Path(head->next, root->right);
}

bool isSubPath(ListNode *head, TreeNode *root)
{
    if (root == nullptr)
    {
        return false;
    }
    if (check_Path(head, root))
    {
        return true;
    }
    return isSubPath(head, root->left) || isSubPath(head, root->right);
}

int main()
{
    return 0;
}