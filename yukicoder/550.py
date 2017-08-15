import math

N = 1000000

def f(x,a,b,c):
    return x**3 + a*x**2 + b*x + c

def SQRT(n):
    l,r= 0,10**46
    while r-l>1:
        m = (l+r)//2
        if m*m <= n:
            l = m
        else:
            r = m
    return l

def main():
    A,B,C = map(int,input().split())

    p = -N+1
    while True:
        if f(p,A,B,C) == 0:
            break
        p += 1

    if p == 0:
        D = A**2 - 4*B
        sq = SQRT(D)
        q = (-A + sq) // 2
        r = (-A - sq) // 2
    else:
        D = (p*B+C)**2 + 4*C*p**3
        sq = SQRT(D)
        q = (p*B+C + sq) // (2*p**2)
        r = (p*B+C - sq) // (2*p**2)

    ans = [p,q,r]
    ans.sort()
    print(' '.join(map(str,ans)))

if __name__ == '__main__':
    main()
