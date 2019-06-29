mod = 10**9 + 7
N = 2002
f = [1]*N

for i in range(1,N):
    f[i] = (i*f[i-1])%mod

def mod_inv(x):
    return pow(x,mod-2,mod)

def C(n,k):
    return (f[n] * mod_inv(f[k]) * mod_inv(f[n-k]))%mod

n,k = map(int,input().split())
for i in range(k):
    ans = 0
    if n-k >= i:
        rem = n-k-i
        ans = C(k-1,i)*C(rem+i+1,rem)
    print(ans%mod)
