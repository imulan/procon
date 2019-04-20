n,d = map(int,input().split())
a = list(map(int,input().split()))
a.sort()
a.reverse()

ans = 0
for i in range(d-1,n,d):
    ans += a[i]
print(ans)
