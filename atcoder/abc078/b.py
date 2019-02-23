x,y,z = map(int,input().split())

i = 1
while i*y + (i+1)*z <= x:
    i += 1
print(i-1)
