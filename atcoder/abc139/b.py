a,b = map(int,input().split())

x = 0
while True:
    if a*x-(x-1) >= b:
        break
    x += 1
print(x)
