def reverseParentheses(s: str) -> str:
    stack = []
    current_string = ""
    for char in s:
        if char == '(':
            stack.append(current_string)
            current_string = ""
        elif char == ')':
            current_string = current_string[::-1]
            current_string = stack.pop() + current_string
        else:
            current_string += char
    return current_string


def problem1190():
    pass


if __name__ == "__main__":
    problem1190()
