#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

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

int minimumSwaps(vector<int> &arr)
{
    int n = arr.size();
    vector<pair<int, int>> valueIndex(n);
    // Pair each element with its index
    for (int i = 0; i < n; i++)
    {
        valueIndex[i] = {arr[i], i};
    }
    // Sort the pairs based on the array value
    sort(valueIndex.begin(), valueIndex.end());
    // To keep track of visited elements
    vector<bool> visited(n, false);
    int swaps = 0;
    for (int i = 0; i < n; i++)
    {
        // If the element is already in the right place or visited, skip it
        if (visited[i] || valueIndex[i].second == i)
        {
            continue;
        }
        // Cycle detection
        int cycleSize = 0;
        int j = i;
        while (!visited[j])
        {
            visited[j] = true;
            // Move to the next index in the cycle
            j = valueIndex[j].second;
            cycleSize++;
        }
        // If cycle size is greater than 1, we need (cycleSize - 1) swaps
        if (cycleSize > 1)
        {
            swaps += (cycleSize - 1);
        }
    }
    return swaps;
}

int BFS(TreeNode *root)
{
    if (!root)
        return 0;
    int min_oper = 0;
    queue<TreeNode *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        int levelSize = Q.size();
        vector<int> level;
        for (int i = 0; i < levelSize; ++i)
        {
            TreeNode *current = Q.front();
            Q.pop();
            level.push_back(current->val);
            if (current->left)
            {
                Q.push(current->left);
            }
            if (current->right)
            {
                Q.push(current->right);
            }
        }
        min_oper += minimumSwaps(level);
    }
    return min_oper;
}

int minimumOperations(TreeNode *root)
{
    return BFS(root);
}

int main()
{
    return 0;
}