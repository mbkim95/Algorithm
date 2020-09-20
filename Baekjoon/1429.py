s = input()

one = 0
zero = 0

if s[0] == '0':
    zero += 1
else:
    one += 1

for i in range(len(s) - 1):
    if s[i] != s[i + 1]:
        if s[i + 1] == '0':
            zero += 1
        else:
            one += 1

print(min(zero, one))
