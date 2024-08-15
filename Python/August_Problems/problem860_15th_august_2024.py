from typing import List


def lemonadeChange(bills: List[int]) -> bool:
    coins = [0, 0]
    for bill in bills:
        if bill == 5:
            coins[0] += 1
        elif bill == 10:
            if coins[0] > 0:
                coins[0] -= 1
                coins[1] += 1
            else:
                return False
        else:
            if coins[1] > 0 and coins[0] > 0:
                coins[1] -= 1
                coins[0] -= 1
            elif coins[0] >= 3:
                coins[0] -= 3
            else:
                return False
        return True


def problem860():
    pass


if __name__ == "__main__":
    problem860()
