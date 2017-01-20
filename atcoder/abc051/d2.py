INF = 123456789

def main():
    n,m = map(int,input().split())

    d = [ [INF for i in range(n)] for j in range(n) ]
    for i in range(n):
        d[i][i] = 0

    a = [0 for _ in range(m)]
    b = [0 for _ in range(m)]
    c = [0 for _ in range(m)]
    for i in range(m):
        a[i],b[i],c[i] = map(int,input().split())
        a[i] -= 1
        b[i] -= 1
        d[a[i]][b[i]] = min(d[a[i]][b[i]], c[i])
        d[b[i]][a[i]] = min(d[b[i]][a[i]], c[i])

    # Warshall-Floyd
    for k in range(n):
        for i in range(n):
            for j in range(n):
                d[i][j] = min(d[i][j], d[i][k]+d[k][j])

    ans = 0
    for i in range(m):
        found = 1
        for j in range(n):
            if d[j][a[i]] + c[i] == d[j][b[i]]:
                found = 0
                break
        ans += found
    print(ans)

if __name__ == '__main__':
    main()
