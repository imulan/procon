n = int(input())
a = list(map(int, input().split()))
a.sort()

x = 1
for i in a:
    x *= i
    if x > 10**18:
        break

ans = x
if ans > 10**18:
    ans = -1
print(ans)
