import fractions

def main():
    a,b,c,d = map(int,input().split())
    a,c = min(a,c),max(a,c)
    b,d = min(b,d),max(b,d)

    c -= a
    a = 0
    d -= b
    b = 0

    if a==c or b==d:
        return 0

    g = fractions.gcd(c,d)
    c//=g
    d//=g
    ct = c+d-1
    return g*ct

if __name__ == '__main__':
    print(main())
