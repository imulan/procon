n, d = map(int, input().split())
ans = 0
for i in range(n):
    x, y = map(int, input().split())
    if x*x + y*y <= d*d:
        ans += 1
print(ans)
