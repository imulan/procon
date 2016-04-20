n,a,b=map(int,input().split())

ans=0
for i in range(n):
	s,d=input().split()
	d=int(d)

	m=1
	if s=="West":
		m=-1

	if d<a:
		ans+=m*a
	elif d<=b:
		ans+=m*d
	else:
		ans+=m*b

if ans>0:
	print("East",ans)
elif ans<0:
	print("West",-ans)
else:
	print(0)
