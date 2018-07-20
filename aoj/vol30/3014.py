D = 360
x = [0 for i in range(D)]

n = int(input())
for i in range(n):
    m,d,v,s = map(int,input().split())
    m -= 1
    d -= 1

    start = 30*m+d
    end = (start+v-1)%D
    h = [False for _ in range(D)]
    for j in range(v):
        y = (start+j)%D
        h[y] = True

    for j in range(D):
        if h[j]:
            x[j] = max(x[j],s)
        else:
            A = abs(start-j)
            if A>D//2:
                A = D-A
            B = abs(end-j)
            if B>D//2:
                B = D-B
            x[j] = max(x[j], s-min(A,B))

print(min(x))
