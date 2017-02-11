INF = 1010101010

def main():
    N,Ma,Mb = map(int,input().split())

    a = [0 for _ in range(N)]
    b = [0 for _ in range(N)]
    c = [0 for _ in range(N)]

    for i in range(N):
        a[i],b[i],c[i] = map(int,input().split())

    dp = [[[INF for k in range(401)] for j in range(401)] for i in range(41)]
    dp[0][0][0] = 0

    for i in range(N):
        for A in range(401):
            for B in range(401):
                dp[i+1][A][B] = min(dp[i+1][A][B], dp[i][A][B])
                if A+a[i]<=400 and B+b[i]<=400:
                    dp[i+1][A+a[i]][B+b[i]] = min(dp[i+1][A+a[i]][B+b[i]], dp[i][A][B]+c[i])

    ans = INF
    for A in range(1,401):
        for B in range(1,401):
            if Ma*B == Mb*A:
                ans = min(ans, dp[N][A][B])

    return -1 if ans == INF else ans

if __name__ == '__main__':
    print(main())
