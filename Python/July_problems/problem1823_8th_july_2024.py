def findTheWinner(n: int, k: int) -> int:
    player = [i for i in range(1, n+1)]
    current = 0
    while len(player) != 1:
        current = (current + (k-1)) % len(player)
        player.pop(current)
    return player[0]


def problem1823():
    print(findTheWinner(5, 2))


if __name__ == "__main__":
    problem1823()
