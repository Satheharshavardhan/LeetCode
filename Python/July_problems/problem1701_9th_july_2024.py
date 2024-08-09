from typing import List


def averageWaitingTime(customers: List[List[int]]) -> float:
    current_time = customers[0][0]
    total_waiting = 0
    i = 0
    while i < len(customers):
        if customers[i][0] <= current_time:
            current_time += customers[i][1]
            total_waiting += (current_time - customers[i][0])
            i += 1
        else:
            current_time = customers[i][0]
    return total_waiting / len(customers)


def problem():
    print(averageWaitingTime([[5, 2], [5, 4], [10, 3], [20, 1]]))


if __name__ == "__main__":
    problem()
