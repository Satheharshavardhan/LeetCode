from typing import List
from collections import Counter


def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
    m1 = Counter(nums1)
    result = []
    for num in nums2:
        if m1[num] > 0:
            result.append(num)
            m1[num] -= 1
    return result


def problem350():
    pass


if __name__ == '__main__':
    problem350()
