n,m = map(int,input().split())
a = list(map(int,input().split()))

ans = 0
for i in a:
    if m < i:
        ans += 1
print(ans)
