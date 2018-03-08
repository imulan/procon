dp = {}
def f(n):
    if n == 0:
        return 1
    if n in dp:
        return dp[n]

    dp[n] = f(n//3) + f(n//5)
    return dp[n]

def main():
    n = int(input())
    print(f(n))

if __name__ == '__main__':
    main()
