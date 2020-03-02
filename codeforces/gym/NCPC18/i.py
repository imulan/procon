n,s = map(int,input().split())

v = [0 for i in range(n)]
for i in range(n):
    t,b = input().split()
    b = int(b)
    v[i] = (t,b)

v = sorted(v, key=lambda x:x[1])
v.reverse()

ans = []
for i in v:
    b = i[1]
    if s >= b:
        s -= b
        ans.append(i[0])

if s == 0:
    print(len(ans))
    for i in ans:
        print(i)
else:
    print(0)
