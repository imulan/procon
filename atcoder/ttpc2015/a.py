s=input()

a=''
b=s[0:2]

if s[2]=='B':
	a='Bachelor'
elif s[2]=='M':
	a="Master"
else:
	a='Doctor'

print(a,b)
