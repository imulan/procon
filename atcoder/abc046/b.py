n,k = map(int,input().split())

ans = k
for i in range(n-1):
    ans *= k-1
print(ans)
