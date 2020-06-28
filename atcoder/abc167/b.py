a, b, c, k = map(int, input().split())

ans = 0
for i, j in zip([1, 0, -1], [a, b, c]):
    x = min(k, j)
    ans += i*x
    k -= x
print(ans)
