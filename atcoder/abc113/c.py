n,m = map(int,input().split())

p,y = [],[]
city = [ [] for i in range(n+1) ]
for i in range(m):
    pp,yy = map(int,input().split())
    p.append(pp)
    y.append(yy)
    city[pp].append(yy)

for i in range(n+1):
    city[i].sort()

for i in range(m):
    ok,ng = 0,len(city[p[i]])
    while ng-ok > 1:
        mid = (ok+ng)//2
        if city[p[i]][mid] <= y[i]:
            ok = mid
        else:
            ng = mid

    print('{:06d}{:06d}'.format(p[i], ok+1))
