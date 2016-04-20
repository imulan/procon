a=int(input())
b=int(input())
c=int(input())

x=[]
x.append(a+b+c)
x.append((a+b)*c)
x.append(a*b+c)
x.append(a*b*c)
print(max(x))
