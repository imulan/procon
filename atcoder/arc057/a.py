target=2*10**12

a,k=map(int,input().split())

ans=0

if k==0:
    ans=target-a
else:
    while a<target:
        ans+=1
        a+=1+k*a

print(ans)
