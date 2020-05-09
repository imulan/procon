a, b, k = map(int, input().split())

if a > k:
    a -= k
else:
    k -= a
    a = 0
    b = max(0, b-k)

print(a, b)
