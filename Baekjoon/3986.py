n = int(input())

answer = 0
for _ in range(n):
    s = input()
    stack = []
    for i in range(len(s)):
        if len(stack) == 0 or stack[-1] != s[i]:
            stack.append(s[i])
        else:
            stack.pop()
    if len(stack) == 0:
        answer += 1
print(answer)
