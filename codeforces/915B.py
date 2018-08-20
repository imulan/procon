n,p,l,r = map(int,input().split())

ans = 10000
if l==1 and r==n:
    ans = 0
else:
    if l==1:
        ans = min(ans, abs(r-p)+1)
    if r==n:
        ans = min(ans, abs(l-p)+1)

    ans = min(ans, abs(l-p)+r-l+2)
    ans = min(ans, abs(r-p)+r-l+2)

print(ans)
