import sys

n = int(sys.stdin.readline().rstrip())
nums = list(map(int, sys.stdin.readline().rstrip().split()))
ops = list(map(int, sys.stdin.readline().rstrip().split()))
min_answer = 1e9
max_answer = -1e9


def dfs(idx, result):
    if idx == n:
        global min_answer
        global max_answer
        min_answer = min(min_answer, result)
        max_answer = max(max_answer, result)
        return

    for i in range(4):
        if ops[i] > 0:
            ops[i] -= 1
            if i == 0: dfs(idx + 1, result + nums[idx])
            elif i == 1: dfs(idx + 1, result - nums[idx])
            elif i == 2: dfs(idx + 1, result * nums[idx])
            else: dfs(idx + 1, int(result / nums[idx]))
            ops[i] += 1

dfs(1, nums[0])
print(max_answer)
print(min_answer)