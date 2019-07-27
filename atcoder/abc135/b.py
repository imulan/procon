n = int(input())
p = list(map(int,input().split()))

ct = 0
for i in range(n):
    if p[i]-1 != i:
        ct += 1

print('YES' if ct <= 2 else 'NO')
