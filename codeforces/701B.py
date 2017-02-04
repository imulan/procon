def main():
    n,m = map(int,input().split())

    ans = [0 for _ in range(m)]

    r = [0 for _ in range(n)]
    c = [0 for _ in range(n)]
    R,C = 0,0

    now = n*n
    for i in range(m):
        x,y = map(int,input().split())
        x -= 1
        y -= 1

        if r[y] == 0 and c[x] == 0:
            r[y] = 1
            c[x] = 1
            now -= (n-R)+(n-C)-1
            R += 1
            C += 1
        elif r[y] == 0:
            r[y] = 1
            now -= (n-C)
            R += 1
        elif c[x] == 0:
            c[x] = 1
            now -= (n-R)
            C += 1

        ans[i] = now

    # output
    for i in range(m):
        if i>0:
            print(' ',end='')
        print(ans[i],end='')
    print()

if __name__ == '__main__':
    main()
