#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

void get_post_order_traversal(Node *root, vector<int> &order)
{
    if (root)
    {
        for (Node *child : root->children)
        {
            get_post_order_traversal(child, order);
        }
        order.push_back(root->val);
    }
}

vector<int> postorder(Node *root)
{
    vector<int> order;
    get_post_order_traversal(root, order);
    return order;
}

int main()
{
    return 0;
}