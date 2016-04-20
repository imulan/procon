n=int(input())
a=list(map(int,input().split()))

c=[]
for i in range(n):
	c.append(input())
c.reverse()

x=[0 for i in range(7)]
ct=[0 for i in range(7)]

for s in c:
	for i in range(7):
		if s[i]=="X":
			ct[i]+=1
			x[i]=max(x[i],ct[i])
		else:
			ct[i]=0

x.sort()
x.reverse()
a.sort()
a.reverse()

ans="YES"
for i in range(7):
	if x[i]>a[i]:
		ans="NO"
print(ans)
