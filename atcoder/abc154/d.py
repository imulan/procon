n, k = map(int, input().split())
p = list(map(int, input().split()))

for i in range(n):
    p[i] = (1+p[i])/2

s = 0
for i in range(k):
    s += p[i]

ans = s
for i in range(k, n):
    s += p[i]
    s -= p[i-k]
    ans = max(ans, s)

print(ans)
