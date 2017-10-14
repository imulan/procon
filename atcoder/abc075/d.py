n,K = map(int,input().split())

x,y = [],[]
xx,yy = [],[]

for _ in range(n):
    X,Y = map(int,input().split())

    x.append(X)
    xx.append(X)
    y.append(Y)
    yy.append(Y)

xx.sort()
yy.sort()

ans = 10**20
for i in range(n):
    for j in range(i):
        lx,rx = xx[j],xx[i]

        num = [0 for _ in range(n+1)]
        for k in range(n):
            if lx <= x[k] <= rx:
                num[yy.index(y[k])+1] += 1

        for k in range(n):
            num[k+1] += num[k]

        for k in range(n):
            for l in range(k):
                ly,ry = yy[l],yy[k]

                if num[k+1] - num[l] >= K:
                    ans = min(ans, (rx-lx)*(ry-ly))

print(ans)
