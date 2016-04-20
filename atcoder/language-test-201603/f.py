s=input()
n=int(input())

for Q in range(n):
	l,r=map(int,input().split())
	x=s[:l-1]
	y=s[l-1:r]
	z=s[r:]
	s=x+y[::-1]+z

print(s)
