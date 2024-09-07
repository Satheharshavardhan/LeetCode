#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// ListNode *modifiedList(vector<int> &nums, ListNode *head)
// {
//     vector<int> list_elements;
//     ListNode *temp = head;
//     while (temp != nullptr)
//     {
//         list_elements.push_back(temp->val);
//         temp = temp->next;
//     }
//     for (const auto &num : nums)
//     {
//         list_elements.erase(remove(list_elements.begin(), list_elements.end(), num), list_elements.end());
//     }
//     if (list_elements.empty())
//     {
//         return nullptr;
//     }
//     ListNode *new_head = new ListNode(list_elements[0]);
//     temp = new_head;
//     for (int i = 1; i < list_elements.size(); i++)
//     {
//         ListNode *new_node = new ListNode(list_elements[i]);
//         temp->next = new_node;
//         temp = new_node;
//     }
//     return new_head;
// }

ListNode *modifiedList(std::vector<int> &nums, ListNode *head)
{
    if (!head)
        return nullptr;
    unordered_set<int> num_set(nums.begin(), nums.end());
    ListNode new_head(0);
    new_head.next = head;
    ListNode *prev = &new_head;
    ListNode *curr = head;
    while (curr != nullptr)
    {
        if (num_set.find(curr->val) != num_set.end())
        {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    return new_head.next;
}

int main()
{
    return 0;
}