x, n = map(int, input().split())
p = set(map(int, input().split()))

d, ans = 100000, -1
for i in range(-200, 200):
    if i in p:
        continue

    t = abs(i-x)
    if t < d:
        d = t
        ans = i
print(ans)
