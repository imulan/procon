import math

n=int(input())
r=[]
for i in range(n):
	r.append(int(input()))

r.sort(reverse=True)

ans=0
for i in range(n):
	m=-1
	if i%2==0:
		m=1

	ans += m*r[i]**2

print(ans*math.pi)
