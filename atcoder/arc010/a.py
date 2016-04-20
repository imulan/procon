n,m,a,b=map(int,input().split())

c=[]
for i in range(m):
    c.append(int(input()))

ans="complete"
for i in range(m):
    if n<=a:
        n+=b

    n-=c[i]

    if n<0:
        ans=i+1
        break

print(ans)
