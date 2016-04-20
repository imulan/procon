import math

T=int(input())
for t in range(T):
	a,b,c=map(int,input().split())

	#2次方程式
	if a!=0:
		D=b*b-4*a*c
		if D>0:
			r=math.sqrt(D)
			x1=(-b-r)/2/a
			x2=(-b+r)/2/a
			if x1>x2:
				x1,x2=x2,x1
			print("2 {0:.15f} {1:.15f}".format(x1,x2))
		elif D==0:
			print("1 {0:.15f}".format(-b/2/a))
		else:
			print(0)
	else:
		#1次方程式
		if b!=0:
			print("1 {0:.15f}".format(-c/b))
		#c=0
		else:
			if c!=0:
				print(0)
			else:
				print(3)
