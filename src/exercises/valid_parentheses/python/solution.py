def isValid(s: str) -> bool:
    Map: dict[str, str] = {")": "(", "]": "[", "}": "{"}
    stack: list[str] = []

    for c in s:
        if c not in Map:
            stack.append(c)
            continue
        if not stack or stack[-1] != Map[c]:
            return False
        stack.pop()

    return not stack
