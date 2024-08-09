def passThePillow(n: int, time: int) -> int:
    direction = True
    has_pillow = 1
    while time > 0:
        if has_pillow == n:
            direction = False
        elif has_pillow == 1:
            direction = True
        if direction:
            has_pillow += 1
        else:
            has_pillow -= 1
        time -= 1
    return has_pillow


def problem2582():
    pass


if __name__ == "__main__":
    problem2582()
