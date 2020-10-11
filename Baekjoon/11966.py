n = int(input())

is_two = True
while n > 1:
    if n % 2 == 1:
        is_two = False
        break
    n //= 2

if is_two:
    print(1)
else:
    print(0)
