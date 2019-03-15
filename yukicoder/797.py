mod = 10**9 + 7

N = 100010
f = [1 for i in range(N)]
invf = [1 for i in range(N)]

for i in range(1,N):
    f[i] = (f[i-1]*i)%mod
    invf[i] = pow(f[i], mod-2, mod)

n = int(input())
a = list(map(int, input().split()))

ans = 0
for i in range(n):
    C = f[n-1]
    C *= invf[i]
    C *= invf[n-1-i]
    ans += C*a[i]
    ans %= mod
print(ans)
