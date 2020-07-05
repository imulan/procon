def solve():
    n = int(input())

    s = 1
    t = 2
    for _ in range(40):
        s += t
        if n % s == 0:
            return n//s
        t *= 2


def main():
    for _ in range(int(input())):
        print(solve())


if __name__ == "__main__":
    main()
