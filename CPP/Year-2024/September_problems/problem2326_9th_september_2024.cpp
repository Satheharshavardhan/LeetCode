#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
{
    vector<vector<int>> matrix(m, vector<int>(n, -1));
    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;
    ListNode *temp = head;
    while (top <= bottom && left <= right && temp)
    {
        for (int j = left; j <= right && temp; ++j)
        {
            matrix[top][j] = temp->val;
            temp = temp->next;
        }
        ++top;
        for (int i = top; i <= bottom && temp; ++i)
        {
            matrix[i][right] = temp->val;
            temp = temp->next;
        }
        --right;
        for (int j = right; j >= left && temp; --j)
        {
            matrix[bottom][j] = temp->val;
            temp = temp->next;
        }
        --bottom;
        for (int i = bottom; i >= top && temp; --i)
        {
            matrix[i][left] = temp->val;
            temp = temp->next;
        }
        ++left;
    }
    return matrix;
}

int main()
{
    return 0;
}