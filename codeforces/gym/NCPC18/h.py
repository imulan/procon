W = 10080
INF = 10**9

def OK(c,t,r,L):
    p = t+r

    for i in range(1,W+1):
        time = W*i
        x,y = time//p,time%p
        y = min(y,t)
        S = c*t*x + c*y
        if S < i*L:
            return False
    return True

def main():
    l,m = map(int,input().split())

    n = ['' for i in range(m)]
    p = [0 for i in range(m)]
    c = [0 for i in range(m)]
    t = [0 for i in range(m)]
    r = [0 for i in range(m)]

    ok = [False for i in range(m)]
    min_cost = INF
    for i in range(m):
        n[i],p[i],c[i],t[i],r[i] = input().split(',')
        p[i] = int(p[i])
        c[i] = int(c[i])
        t[i] = int(t[i])
        r[i] = int(r[i])

        ok[i] = OK(c[i],t[i],r[i],l)
        if ok[i]:
            min_cost = min(min_cost, p[i])

    ans = []
    for i in range(m):
        if ok[i] and p[i]==min_cost:
            ans.append(n[i])

    if not ans:
        ans.append('no such mower')

    for i in ans:
        print(i)

if __name__ == "__main__":
    main()
