a,b,c = map(int,input().split())

d = 0
s = 0
while s < c:
    d += 1
    if d%7 == 0:
        s += b
    s += a
print(d)
