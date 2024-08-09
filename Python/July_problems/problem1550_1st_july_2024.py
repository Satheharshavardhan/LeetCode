from typing import List


def check_odd(num: int):
    if num % 2 == 1:
        return True
    else:
        return False


def threeConsecutiveOdds(self, arr: List[int]) -> bool:
    if len(arr) < 3:
        return False
    for i in range(0, len(arr)-2):
        if check_odd(arr[i]) and check_odd(arr[i+1]) and check_odd(arr[i+2]):
            return True
    return False


def problem1550():
    pass


if __name__ == "__main__":
    problem1550()
