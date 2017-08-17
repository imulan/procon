import math

def F(n):
    p,q = 0,0
    for i in range(n):
        p += 0.81**(i+1)
        q += 0.9**(i+1)
    return math.sqrt(p)/q

def f(n):
    F_INF = math.sqrt(0.81/(1-0.81)) / (0.9/(1-0.9))
    return 1200*(F(n)-F_INF) / (F(1)-F_INF)

def g(X):
    return 2.0**(X/800)

def inv_g(X):
    l,r = 0,191919
    for _ in range(100):
        m = (l+r)/2
        if g(m)<=X:
            l = m
        else:
            r = m
    return l

def main():
    n = int(input())

    p,q = 0,0
    for i in range(n):
        perf = int(input())
        p += g(perf)*(0.9**(i+1))
        q += 0.9**(i+1)

    print(inv_g(p/q)-f(n))

if __name__ == '__main__':
    main()
