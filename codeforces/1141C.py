n = int(input())
q = list(map(int,input().split()))
p = [0 for i in range(n)]

for i in range(1,n):
    p[i] = q[i-1]+p[i-1]

mn = min(p)
for i in range(n):
    p[i] -= mn-1

ok = True
used = set()
for i in p:
    if i<1 or n<i:
        ok = False
    if i in used:
        ok = False
    used.add(i)

if ok:
    print(' '.join(map(str,p)))
else:
    print(-1)
