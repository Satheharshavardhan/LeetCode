from typing import List
from collections import Counter


def solution961(nums: List[int]) -> int:
    num_count = Counter(nums)
    for key, val in num_count.items():
        if val > 1:
            return key


if __name__ == "__main__":
    result = solution961([1, 2, 3, 3])
    print(result)
