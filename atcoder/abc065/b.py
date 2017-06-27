n = int(input())
a = []
for _ in range(n):
    s = int(input())
    a.append(s-1)

vis = [False for _ in range(n)]

ans = 0
now = 0
while True:
    if vis[now]:
        ans = -1
        break

    vis[now] = True
    ans += 1
    now = a[now]
    if now == 1:
        break

print(ans)
