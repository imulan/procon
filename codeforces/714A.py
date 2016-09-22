l1,r1,l2,r2,k = map(int,input().split())

ans = 0
if l2<=r1 and l1<=r2:
    L = max(l1,l2)
    R = min(r1,r2)
    ans = R-L+1
    if L <= k <= R:
        ans -= 1

print(ans)
