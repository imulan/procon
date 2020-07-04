def solve():
    x = list(map(int, input().split()))

    ans = 10**10
    for i in range(-1, 2):
        for j in range(-1, 2):
            for k in range(-1, 2):
                a, b, c = x
                a += i
                b += j
                c += k
                t = abs(a-b)+abs(b-c)+abs(a-c)
                ans = min(ans, t)

    return ans


def main():
    t = int(input())
    for _ in range(t):
        print(solve())


if __name__ == "__main__":
    main()
