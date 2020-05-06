x = int(input())

y = 100
ans = 0
while y < x:
    ans += 1
    y = y*101//100
print(ans)
