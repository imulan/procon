n=int(input())
for times in range(n):
	s=input()
	ans="NA"

	#Aの可能性
	if s[:2]==">'" and s[-1]=="~":
		t=s[2:-1].split("#")

		if len(t)==2 and len(t[0])>0:
			valid=True
			for v in t[0]:
				if v!="=":
					valid=False
					break
			if valid and t[0]==t[1]:
				ans="A"

	#Bの可能性
	elif s[:2]==">^" and s[-2:]=="~~":
		t=s[2:-2]

		if len(t)>0 and len(t)%2==0:
			valid=True
			for i in range(0,len(t),2):
				if t[i:i+2]!="Q=":
					valid=False
					break
			if valid:
				ans="B"

	print(ans)
