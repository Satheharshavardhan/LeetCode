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

vector<int> nodesBetweenCriticalPoints(ListNode *head)
{
    ListNode *current = head->next;
    int prev = head->val;
    int i = 2;
    vector<int> critical_index;
    while (current->next != NULL)
    {
        if (current->val > prev and current->val > current->next->val)
        {
            critical_index.push_back(i);
        }
        else if (current->val < prev and current->val < current->next->val)
        {
            critical_index.push_back(i);
        }
        prev = current->val;
        current = current->next;
        i += 1;
    }
    if (critical_index.size() < 2)
    {
        return {-1, -1};
    }
    int min_distance = INT_MAX;
    int max_distance = critical_index.back() - critical_index.front();

    for (size_t i = 1; i < critical_index.size(); i++)
    {
        int distance = critical_index[i] - critical_index[i - 1];
        min_distance = min(min_distance, distance);
    }
    return {min_distance, max_distance};
}

int main()
{
    return 0;
}