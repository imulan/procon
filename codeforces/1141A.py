def solve():
    n,m = map(int,input().split())
    if m%n != 0:
        return -1

    t = m//n

    ans = 0
    for i in [2,3]:
        while t%i == 0:
            t //= i
            ans += 1

    if t > 1:
        return -1
    return ans

if __name__ == "__main__":
    print(solve())
