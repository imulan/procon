n = int(input())
x = list(map(int, input().split()))

ans = 10**10
for i in range(101):
    t = 0
    for j in x:
        d = i-j
        t += d*d
    ans = min(ans, t)
print(ans)
