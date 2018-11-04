mod = 10**9 + 7

def main():
    h,w,k = map(int,input().split())
    k -= 1

    if w == 1:
        return 1

    dp = [0 for i in range(w)]
    dp[0] = 1

    for i in range(h):
        nx = [0 for _ in range(w)]

        for mask in range(1<<(w-1)):
            bar = [0 for _ in range(w-1)]
            for j in range(w-1):
                bar[j] = (mask>>j&1)

            valid = True
            for j in range(w-2):
                if bar[j] == 1 and bar[j+1] == 1:
                    valid = False

            if not valid:
                continue

            for j in range(w):
                if j>0 and bar[j-1]:
                    nx[j-1] += dp[j]
                    nx[j-1] %= mod
                elif j+1<w and bar[j]:
                    nx[j+1] += dp[j]
                    nx[j+1] %= mod
                else:
                    nx[j] += dp[j]
                    nx[j] %= mod

        dp = nx

    return dp[k]

if __name__ == '__main__':
    print(main())
