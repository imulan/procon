a,b = map(int,input().split())

s = set()
for i in range(a+1):
    for j in range(b+1):
        v = i + 5*j
        if v > 0:
            s.add(v)

for x in sorted(list(s)):
    print(x)
