def main():
    n,m = map(int,input().split())
    l = list(map(int,input().split()))
    for i in range(m):
        l[i] -= 1

    a = [-1 for i in range(n)]

    now = l[0]
    for i in range(1,m):
        if a[now] == -1:
            for j in range(1,n+1):
                if (now + j)%n == l[i]:
                    a[now] = j
                    break

        now = (now+a[now])%n
        if now != l[i]:
            print(-1)
            return

    ct = [0 for i in range(n+1)]
    for i in range(n):
        if a[i]>0:
           ct[a[i]] += 1
           if ct[a[i]] > 1:
               print(-1)
               return

    idx = 1
    for i in range(n):
        while idx <= n and ct[idx] != 0:
            idx += 1

        if a[i] == -1:
            if idx > n:
                print(-1)
                return
            a[i] = idx
            ct[idx] += 1

    print(' '.join(map(str,a)))

if __name__ == '__main__':
    main()
