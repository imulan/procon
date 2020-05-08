a, b = map(int, input().split())

ans = -1
for x in range(10000, 0, -1):
    ta, tb = x*8//100, x*10//100
    if a == ta and b == tb:
        ans = x

print(ans)
