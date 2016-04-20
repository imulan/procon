n=int(input())

x=[]
for i in range(3):
	x.append(int(input()))
x.sort()
x.reverse()

ans=0
t=0
while t<n:
	t+=x[ans%3]
	ans+=1

print(ans)
