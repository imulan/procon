import fractions

LIM = 10**19

def main():
    n = int(input())
    m = int(input())

    g = fractions.gcd(n,m)
    n,m = n//g,m//g

    # 整数の時の処理
    if m == 1:
        while n%10 == 0:
            n //= 10
        return n%10

    p2 = []
    a = 2
    while a < LIM:
        p2.append(a)
        a *= 2

    p5 = []
    a = 5
    while a < LIM:
        p5.append(a)
        a *= 5

    # 分母チェック
    t_m = m
    for d in reversed(p2):
        if t_m % d == 0:
            t_m //= d
            break
    for d in reversed(p5):
        if t_m % d == 0:
            t_m //= d
            break

    if t_m != 1:
        return -1

    while True:
        while n < m:
            n *= 10
        q = n//m
        n -= q*m

        if n == 0:
            return q

if __name__ == '__main__':
    print(main())
