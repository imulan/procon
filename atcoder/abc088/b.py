n = int(input())
a = list(map(int,input().split()))

a.sort()
a.reverse()

ans = 0
for i in range(n):
    ans += (-1)**i * a[i]
print(ans)
