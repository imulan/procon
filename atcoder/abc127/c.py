n,m = map(int,input().split())

L,R = 1,n
for _ in range(m):
    l,r = map(int,input().split())
    L = max(L,l)
    R = min(R,r)

print(max(0,R-L+1))
