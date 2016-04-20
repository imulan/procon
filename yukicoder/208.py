x,y=map(int,input().split())
a,b=map(int,input().split())

ans=max(x,y)
if x==y and a==b and x>a:
    ans+=1
print(ans)
