x,y,z,k = map(int,input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
c = list(map(int,input().split()))

for l in [b,c]:
    p = []
    for i in a:
        for j in l:
            p.append(i+j)
    a = sorted(p, reverse=True)[:k]

for i in a:
    print(i)
