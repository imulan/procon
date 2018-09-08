import fractions

n,X = map(int,input().split())
x = list(map(int,input().split()))

ans = abs(X-x[0])
for i in x:
    ans = fractions.gcd(ans, abs(X-i))
print(ans)
