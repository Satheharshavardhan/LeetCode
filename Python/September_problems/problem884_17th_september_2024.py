from typing import List, Counter


def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
    word1 = s1.split(' ')
    word2 = s2.split(' ')
    count1 = Counter(word1)
    count2 = Counter(word2)
    result = []
    for key, val in count1.items():
        if val == 1 and key not in count2.keys():
            result.append(key)
    for key, val in count2.items():
        if val == 1 and key not in count1.keys():
            result.append(key)
    return result


def problem884():
    pass


if __name__ == "__main__":
    problem884()
