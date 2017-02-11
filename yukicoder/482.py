def main():
    n,k = map(int,input().split())
    d = list(map(int,input().split()))

    f = [-1 for _ in range(n)]

    for i in range(n):
        d[i] -= 1
        f[d[i]] = i

    ct = 0
    for i in range(n):
        if d[i] == i:
            continue

        x,y = i,f[i]
        d[x],d[y] = d[y],d[x]
        f[d[x]],f[d[y]] = x,y
        ct += 1

    if ct > k:
        return 'NO'

    return 'YES' if (k-ct)%2 == 0 else 'NO'

if __name__ == '__main__':
    print(main())
