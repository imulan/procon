n = int(input())
x,y,h = [],[],[]
idx = 0
for i in range(n):
    a,b,c = map(int,input().split())
    x.append(a)
    y.append(b)
    h.append(c)
    if c != 0:
        idx = i

for cx in range(101):
    for cy in range(101):
        # h[idx] = H - abs(x[idx]-cx) - abs(y[idx]-cy)
        H = h[idx] + abs(x[idx]-cx) + abs(y[idx]-cy)

        ok = True
        for i in range(n):
            if h[i] != max(H - abs(x[i]-cx) - abs(y[i]-cy), 0):
                ok = False
        if ok:
            print(cx,cy,H)
