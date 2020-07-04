def solve():
    n, k = map(int, input().split())

    b = n//k
    n -= b*k
    x = min(k//2, n)
    return b*k+x


def main():
    t = int(input())
    for _ in range(t):
        print(solve())


if __name__ == "__main__":
    main()
