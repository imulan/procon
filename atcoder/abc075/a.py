a = list(map(int,input().split()))
a.sort()

ans = a[0]
if a[0] == a[1]:
    ans = a[2]
print(ans)
