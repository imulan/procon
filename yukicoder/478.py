def main():
    n,k = map(int,input().split())

    w = [0 for _ in range(n)]

    now = 0
    for i in range(0,n,2):
        w[i] = now
        now += 1

    now = 10**9
    for i in range(1,n,2):
        w[i] = now
        now -= 1

    idx = n-1-k
    for i in range(idx+1,n):
        w[i] = w[idx]

    ans = ''
    for i in range(n):
        if i > 0:
            ans += ' '
        ans += str(w[i])

    return ans

if __name__ == '__main__':
    print(main())
