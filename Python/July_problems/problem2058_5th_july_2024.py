from typing import Optional, List


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def nodesBetweenCriticalPoints(head: Optional[ListNode]) -> List[int]:
    current = head.next
    prev = head.val
    critical_index = []
    i = 2
    while current.next:
        if (current.val > prev and current.val > current.val.val) or (current.val < prev and current.val < current.val.val):
            critical_index.append(i)
        prev = current.val
        current = current.next
        i += 1
    if len(critical_index) <= 1:
        return [-1, -1]
    prev = float('inf')
    for i in range(len(1, critical_index)):
        diff = critical_index[i] - critical_index[i-1]
        prev = min(prev, diff)
    return [prev, critical_index[-1]-critical_index[0]]


def problem2058():
    pass


if __name__ == "__main__":
    problem2058()
