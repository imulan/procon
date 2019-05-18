from fractions import Fraction

def NG():
    print("IMPOSSIBLE")

def solve():
    n = int(input())

    C,J = [],[]
    for i in range(n):
        c,j = map(int,input().split())
        C.append(c)
        J.append(j)

    INF = 10**10
    L = Fraction(0,1)
    R = Fraction(INF)
    for i in range(n-1):
        j = i+1
        if C[i] == C[j]:
            if J[i]-J[j] > 0:
                NG()
                return
        elif J[i] == J[j]:
            if C[j]-C[i] < 0:
                NG()
                return
        else:
            if J[i]-J[j]>0:
                if C[j]-C[i]<0:
                    NG()
                    return
                else:
                    R = min(R, Fraction(C[j]-C[i], J[i]-J[j]))
            else:
                if C[i]-C[j]>0:
                    L = max(L, Fraction(C[i]-C[j], J[j]-J[i]))

    if L >= R:
        NG()
        return
    M = (L+R)/2

    ng,ok = 0,INF
    while ok-ng>1:
        mid = (ng+ok)//2

        f = M.limit_denominator(mid)
        if L < f < R:
            ok = mid
        else:
            ng = mid

    x = ok

    ng,ok = 0,INF
    while ok-ng>1:
        mid = (ng+ok)//2

        if mid*L.denominator > x*L.numerator:
            ok = mid
        else:
            ng = mid

    y = ok
    print(x,y)

def main():
    T = int(input())
    for i in range(T):
        print("Case #{}: ".format(i+1), end="")
        solve()

if __name__ == "__main__":
    main()
