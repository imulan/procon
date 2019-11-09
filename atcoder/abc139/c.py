n = int(input())
h = list(map(int,input().split()))

a = [0 for _ in range(n)]
for i in range(n-1,0,-1):
    if h[i-1] >= h[i]:
        a[i-1] = a[i]+1
print(max(a))
