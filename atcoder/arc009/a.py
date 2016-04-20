n=int(input())
ans=0
for i in range(n):
    a,b=map(int,input().split())
    ans+=a*b*105
print(ans//100)
