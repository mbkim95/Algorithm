def solution(numbers):
    result = set()
    n = len(numbers)
    for i in range(n - 1):
        for j in range(i + 1, n):
            result.add(numbers[i] + numbers[j])
    answer = list(result)
    answer.sort()
    return answer