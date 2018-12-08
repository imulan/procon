n,k = map(int,input().split())
h = []
for i in range(n):
    h.append(int(input()))
h.sort()

ans = 10**10
for i in range(n-k+1):
    j = i+k-1
    ans = min(ans, h[j]-h[i])
print(ans)
