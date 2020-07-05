def solve():
    n, m = map(int, input().split())
    return m*min(2, n-1)


if __name__ == "__main__":
    for _ in range(int(input())):
        print(solve())
