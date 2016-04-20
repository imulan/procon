n,a,b=map(int,input().split())
ans="Ant"
if n%(a+b)==0 or n%(a+b)>a:
    ans="Bug"
print(ans)
