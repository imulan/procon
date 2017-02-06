def main():
    n,L,v1,v2,k = map(int,input().split())

    group = (n+k-1)//k

    l,r = 0,L

    for _ in range(100):
        m = (l+r)/2
        t2 = m/v2
        d = m - v1*t2
        T = d/(v1+v2)

        if v1*(t2+T)*(group-1) + m <= L:
            l = m
        else:
            r = m

    ans = l/v2 + (L-l)/v1

    print("{0:.10f}".format(ans))

if __name__ == '__main__':
    main()
