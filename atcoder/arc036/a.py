n,k=map(int,input().split())
t=[]
for i in range(n):
    t.append(int(input()))

ans=-1
for i in range(2,n):
    if t[i]+t[i-1]+t[i-2]<k:
        ans=i+1
        break
print(ans)
