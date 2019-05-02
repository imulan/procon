n,m = map(int,input().split())

ct = [0 for _ in range(m)]
for i in range(n):
    a = list(map(int,input().split()))
    for j in range(1,len(a)):
        ct[a[j]-1] += 1

ans = 0
for i in range(m):
    if ct[i] == n:
        ans += 1
print(ans)
