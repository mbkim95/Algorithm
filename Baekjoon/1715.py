import sys
import heapq

n = int(sys.stdin.readline().strip())
card = []

for i in range(n):
    heapq.heappush(card, int(sys.stdin.readline().rstrip()))

answer = 0
while len(card) > 1:
    a = heapq.heappop(card)
    b = heapq.heappop(card)
    answer += (a + b)
    heapq.heappush(card, a + b)
print(answer)
