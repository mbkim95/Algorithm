import sys

while True:
    tmp = sys.stdin.readline().rstrip()
    if tmp == '0':
        break
    left = 0
    right = len(tmp) - 1
    is_palindrome = True
    while left <= right:
        if tmp[left] != tmp[right]:
            print("no")
            is_palindrome = False
            break
        left += 1
        right -= 1
    if is_palindrome:
        print("yes")
