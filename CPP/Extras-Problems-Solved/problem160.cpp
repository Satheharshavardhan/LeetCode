#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int get_Length(ListNode *head)
{
    int length = 0;
    while (head != NULL)
    {
        length++;
        head = head->next;
    }
    return length;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    int lenA = get_Length(headA);
    int lenB = get_Length(headB);
    while (lenA > lenB)
    {
        headA = headA->next;
        lenA--;
    }
    while (lenB > lenA)
    {
        headB = headB->next;
        lenB--;
    }
    while (headA != headB)
    {
        headA = headA->next;
        headB = headB->next;
    }
    return headA;
}

int main()
{
    return 0;
}