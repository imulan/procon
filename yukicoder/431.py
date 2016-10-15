d1,d2,d3,s=map(int,input().split())

ans="SURVIVED"
if s==0 and d1+d2+d3>=2:
    ans="DEAD"
print(ans)
