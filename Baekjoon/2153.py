import math

MAX = 20 * 52

array = [True for _ in range(MAX + 1)]

for i in range(2, int(math.sqrt(MAX)) + 1):
    if array[i]:
        j = 2
        while i * j <= MAX:
            array[i * j] = False
            j += 1
s = input()
sum = 0

for i in range(len(s)):
    if 'a' <= s[i] <= 'z':
        sum += (ord(s[i]) - ord('a')) + 1
    else:
        sum += (ord(s[i]) - ord('A') + 27)
if array[sum]:
    print('It is a prime word.')
else:
    print('It is not a prime word.')
