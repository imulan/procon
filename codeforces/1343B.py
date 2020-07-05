def solve():
    n = int(input())
    if n % 4 != 0:
        print('NO')
        return

    x = [0 for _ in range(n)]
    for i in range(n//2):
        e = 4*i+2
        x[i] = e
        x[n//2+i] = e-1 if i % 2 == 0 else e+1

    print('YES')
    print(' '.join(map(str, x)))


def main():
    for _ in range(int(input())):
        solve()


if __name__ == "__main__":
    main()
