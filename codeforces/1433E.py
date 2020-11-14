def f(n):
    ret = 1
    for i in range(1, n+1):
        ret *= i
    return ret


def C(n, r):
    return f(n)//f(r)//f(n-r)


def main():
    n = int(input())
    ans = C(n, n//2) * f(n//2-1) * f(n//2-1) // 2
    print(ans)


if __name__ == "__main__":
    main()
