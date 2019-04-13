n = int(input())
h = list(map(int,input().split()))

ans = 0
for i in range(n):
    a = 1
    for j in range(i):
        if h[j] > h[i]:
            a = 0
    ans += a
print(ans)
