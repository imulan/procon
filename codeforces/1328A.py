def solve():
    a, b = map(int, input().split())
    return (b-a % b) % b


def main():
    t = int(input())
    for _ in range(t):
        print(solve())


if __name__ == "__main__":
    main()
