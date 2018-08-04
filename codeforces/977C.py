n,k = map(int,input().split())
a = sorted(list(map(int,input().split())))

ans = 1
if k==0:
    if a[0]==1:
        ans = -1
else:
    ans = a[k-1]
    if k<n and a[k]==ans:
        ans = -1
print(ans)
