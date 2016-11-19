a,b=map(int,input().split())

ans='E'
if a+b > a*b:
    ans='S'
if a+b < a*b:
    ans='P'
print(ans)
