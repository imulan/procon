n,k = map(int,input().split())
h = sorted(list(map(int,input().split())))
print(0 if n<=k else sum(h[0:n-k]))
