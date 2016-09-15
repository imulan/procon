n=int(input())
k=int(input())
x=int(input())
y=int(input())

ans=0
if n<=k:
    ans=x*n
else:
    ans=x*k+y*(n-k)
print(ans)
