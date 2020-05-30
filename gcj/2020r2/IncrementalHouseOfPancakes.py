def s(x):
    return x*(x+1)//2


def odd(x):
    if x < 0:
        return 0
    a = (x+1)//2
    return a*a


def even(x):
    if x < 0:
        return 0

    a = x//2
    return a*(a+1)


def calc(l, r):
    if l > r:
        return 0

    if l % 2 != r % 2:
        r -= 1

    if r % 2 == 0:
        return even(r) - even(l-2)
    else:
        return odd(r) - odd(l-2)


def solve():
    L, R = map(int, input().split())

    x = 1
    if L >= R:
        ok, ng = 0, 10**10
        while ng-ok > 1:
            mid = (ok+ng)//2

            if L-s(mid) < R:
                ng = mid
            else:
                ok = mid

        L -= s(ok)
        x = ng
    else:
        # L < R
        ok, ng = 0, 10**10
        while ng-ok > 1:
            mid = (ok+ng)//2

            if R-s(mid) <= L:
                ng = mid
            else:
                ok = mid

        R -= s(ok)
        x = ng
        # まだ L < R

        if R - x >= 0:
            R -= x
            x += 1
        # ここで L >= R

    # L >= R
    # LRLRLR...
    # L-=x, R-=x+1, L-=x+2, ...
    ok, ng = x-1, 2*10**10
    while ng-ok > 1:
        mid = (ok+ng)//2

        tl, tr = L-calc(x, mid), R-calc(x+1, mid)
        if tl >= 0 and tr >= 0:
            ok = mid
        else:
            ng = mid

    L -= calc(x, ok)
    R -= calc(x+1, ok)
    print(ok, L, R)


def main():
    T = int(input())
    for i in range(T):
        print("Case #{}: ".format(i+1), end='')
        solve()


if __name__ == "__main__":
    main()
