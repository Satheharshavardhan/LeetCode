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

ListNode *mergeNodes(ListNode *head)
{
    ListNode *current = head->next;
    ListNode *temp = new ListNode(0);
    ListNode *tail = temp;
    int sum = 0;

    while (current != nullptr)
    {
        if (current->val != 0)
        {
            sum += current->val;
        }
        else
        {
            tail->next = new ListNode(sum);
            tail = tail->next;
            sum = 0;
        }
        current = current->next;
    }

    return temp->next;
}

ListNode *list_to_linked_list(const vector<int> &list)
{
    if (list.empty())
        return nullptr;

    ListNode *head = new ListNode(list[0]);
    ListNode *current = head;

    for (size_t i = 1; i < list.size(); ++i)
    {
        current->next = new ListNode(list[i]);
        current = current->next;
    }

    return head;
}

void print_list(ListNode *head)
{
    ListNode *current = head;
    while (current != nullptr)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    vector<int> list = {0, 3, 1, 0, 4, 5, 2, 0};
    ListNode *head = list_to_linked_list(list);
    ListNode *merged = mergeNodes(head);
    print_list(merged);
    return 0;
}
