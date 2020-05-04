n, m = map(int, input().split())
h = list(map(int, input().split()))

G = [[] for i in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    a, b = a-1, b-1
    G[a].append(b)
    G[b].append(a)

ans = 0
for i in range(n):
    mx = 0
    for j in G[i]:
        mx = max(mx, h[j])
    if mx < h[i]:
        ans += 1

print(ans)
