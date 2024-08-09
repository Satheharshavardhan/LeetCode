from typing import List


def minOperations(logs: List[str]) -> int:
    current = 1
    for log in logs:
        if "../" in log and current != 1:
            current -= 1
        elif "./" in log:
            pass
        else:
            current += 1
    return current-1


def problem1598():
    pass


if __name__ == "__main__":
    problem1598()
