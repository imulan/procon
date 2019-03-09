n,m,c = map(int,input().split())
b = list(map(int,input().split()))

ans = 0
for i in range(n):
    a = list(map(int,input().split()))
    t = c
    for j in range(m):
        t += a[j]*b[j]
    if t > 0:
        ans += 1
print(ans)
