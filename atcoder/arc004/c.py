import fractions

def main():
    x,y = map(int,input().split('/'))
    G = fractions.gcd(x,y)

    x = x//G
    y = y//G

    found = False
    for i in range(2):
        n = 2*x//y + i

        if n <= 0:
            continue

        if (n*x)%y == 0:
            m = n*(n+1)//2 - n*x//y
            if 1 <= m <= n:
                print(n,m)
                found = True

    if not found:
        print('Impossible')

if __name__ == '__main__':
    main()
