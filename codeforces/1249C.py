N = 38

def f(x):
    ret = 0
    for i in range(N+1):
        if x>>i&1:
            ret += 3**i
    return ret

def solve():
    n = int(input())

    ng,ok = -1, 1<<N
    while ok-ng>1:
        mid = (ok+ng)//2
        if f(mid) >= n:
            ok = mid
        else:
            ng = mid

    return f(ok)

def main():
    q = int(input())
    for _ in range(q):
        print(solve())

if __name__ == "__main__":
    main()
