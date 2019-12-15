n,d = map(int,input().split())

x = []
for i in range(n):
    x.append(list(map(int,input().split())))

ans = 0
for i in range(n):
    for j in range(i+1,n):
        f = 0
        for k in range(d):
            f += (x[i][k]-x[j][k])**2

        m = 1
        while m*m < f:
            m += 1
        if m*m == f:
            ans += 1

print(ans)
