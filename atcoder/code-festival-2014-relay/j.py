n,k=map(int,input().split())

ans="first"
if n%2==0 and k<n/2:
	ans="second"
print(ans)
