from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
    current = head
    answer = ListNode()
    tail = answer
    sum = 0
    while current != None:
        if current.val != 0:
            sum += current.val
        else:
            tail.next = ListNode(sum)
            tail = tail.next
            sum = 0
        current = current.next
    return answer.next


def problem2181():
    pass


if __name__ == '__main__':
    problem2181()
