a,b=2,1000

for i in range(100):
	if a<b:
		a*=2
		print("a! ",end="")
	else:
		b*=2
		print("b! ",end="")
	print(a,b)
