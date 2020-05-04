k, n = map(int, input().split())
a = list(map(int, input().split()))
a.sort()

x = a[:]
for i in a:
    x.append(i+k)

ans = k
for i in range(n):
    ans = min(ans, x[n-1+i]-x[i])
print(ans)
