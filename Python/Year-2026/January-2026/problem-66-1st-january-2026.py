from typing import List


def solution66(digits: List[int]) -> List[int]:
    num = "".join(str(i) for i in digits)
    num_int = int(num) + 1
    num = str(num_int)
    result = [int(i) for i in num]
    return result


if __name__ == "__main__":
    print(solution66([1, 2, 3]))
