h = int(input())

ans = 0
x = 1
while h > 0:
    ans += x
    x *= 2
    h //= 2

print(ans)
