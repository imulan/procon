d=list(map(int,input().split()))
j=list(map(int,input().split()))

ans=0
for i in range(7):
    ans+=max(d[i],j[i])
print(ans)
