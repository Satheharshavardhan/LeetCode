from typing import List


def identify_leader(members: List[int]) -> List[int]:
    leaders = []
    leaders.append(members[-1])
    for i in range(len(members)-2, -1, -1):
        if members[i] > leaders[-1]:
            leaders.append(members[i])
    return leaders


print(identify_leader([7, 6, 9, 5, 3, 78, 9, 12, 4]))
