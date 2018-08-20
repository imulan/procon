n,k = map(int,input().split())
a = list(map(int,input().split()))

ans = 111
for v in a:
    if k%v == 0:
        ans = min(ans, k//v)
print(ans)
