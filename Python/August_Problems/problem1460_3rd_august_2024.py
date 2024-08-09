from typing import List


def canBeEqual(target: List[int], arr: List[int]) -> bool:
    target.sort()
    arr.sort()
    return target == arr


def problem1460():
    pass


if __name__ == "__main__":
    problem1460()
