def numWaterBottles(numBottles: int, numExchange: int) -> int:
    result = 0
    empty_bottel = 0
    while numBottles > 0:
        result += numBottles
        empty_bottel += numBottles
        numBottles = empty_bottel//numExchange
        empty_bottel -= numExchange*numBottles
    return result


def problem1518():
    pass


if __name__ == "__main__":
    problem1518()
