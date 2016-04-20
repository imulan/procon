n,m=map(int,input().split())
p=list(map(int,input().split()))
s=list(map(int,input().split()))

ans=0
for v in s:
	ans+=p[v-1]
print(ans)
