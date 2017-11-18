def main():
    H,W = map(int,input().split())

    C = 10
    c = []
    for i in range(C):
        c.append(list(map(int,input().split())))

    a = []
    for i in range(H):
        a.append(list(map(int,input().split())))

    for k in range(C):
        for i in range(C):
            for j in range(C):
                c[i][j] = min(c[i][j],c[i][k]+c[k][j])

    ans = 0
    for i in range(H):
        for j in range(W):
            if a[i][j] != -1:
                ans += c[a[i][j]][1]
    print(ans)

if __name__ == '__main__':
    main()
