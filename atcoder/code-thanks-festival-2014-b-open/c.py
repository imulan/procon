n=int(input())
v=list(map(int,input().split()))
f=list(map(int,input().split()))

ans=0
for i in range(n):
	if f[i]*2>v[i]:
		ans+=1
print(ans)
