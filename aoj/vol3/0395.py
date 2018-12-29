n = int(input())
a = list(map(int,input().split()))
w = list(map(int,input().split()))

INF = 10**9
x = [INF]*2
for i in range(n):
    x[a[i]] = min(x[a[i]], w[i])

ans = sum(x)
if ans >= INF:
    ans = 0
print(ans)
