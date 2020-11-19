import sys

s = sys.stdin.readline().rstrip()

joi_cnt = 0
ioi_cnt = 0
for i in range(len(s) - 2):
    tmp = s[i:i + 3]
    if tmp == 'JOI':
        joi_cnt += 1
    elif tmp == 'IOI':
        ioi_cnt += 1
print(joi_cnt)
print(ioi_cnt)
