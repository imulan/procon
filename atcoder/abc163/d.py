MOD = 10**9+7

n,k = map(int,input().split())

ans = 0
pre,suf = 0,0
for i in range(1,n+2):
    pre += i-1
    suf += n+1-i

    if i >= k:
        ans += suf-pre+1
        ans %= MOD

print(ans)
