def bestClosingTime(customer: str) -> int:
    n = len(customer)
    prefixY = [0] * (n + 1)
    prefixN = [0] * (n + 1)

    for i in range(1, n + 1):
        prefixY[i] = prefixY[i - 1] + (1 if customer[i - 1] == 'Y' else 0)
        prefixN[i] = prefixN[i - 1] + (1 if customer[i - 1] == 'N' else 0)

    max_score = -1
    best_hour = 0

    for j in range(n + 1):
        score = prefixY[j] + (prefixN[n] - prefixN[j])
        if score > max_score:
            max_score = score
            best_hour = j

    print(best_hour)


if __name__ == "__main__":
    bestClosingTime()
