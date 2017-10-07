f,n,k = map(int,input().split())

fact = [1 for _ in range(101)]
for i in range(2,101):
    fact[i] = fact[i-1]*i

ans = 0

# k-th largest == i
for a in range(1,f+1):
    # number of larger nums
    for b in range(0,k):
        # number of i
        for c in range(max(0,k-b),n-b+1):
            p = fact[n] * ((f-a)**b) * ((a-1)**(n-b-c))
            q = fact[b] * fact[c] * fact[n-b-c] * (f**n)
            ans += a*p/q

print('{0:.10f}'.format(ans))
