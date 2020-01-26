a,b = map(int,input().split())

x = ''
for i in range(a):
    x += str(b)

y = ''
for i in range(b):
    y += str(a)

print(min(x,y))
