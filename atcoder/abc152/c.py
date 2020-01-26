n = int(input())
p = list(map(int,input().split()))

ans = 0
mn = n
for i in range(n):
    mn = min(mn,p[i])
    if p[i] <= mn:
        ans += 1

print(ans)
