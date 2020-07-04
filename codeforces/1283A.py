def solve():
    h, m = map(int, input().split())
    return 60*24-(h*60+m)


def main():
    t = int(input())
    for _ in range(t):
        print(solve())


if __name__ == "__main__":
    main()
