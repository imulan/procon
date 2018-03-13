def f(n):
    return n*(n+1)//2

def main():
    n = int(input())
    l,r = 0,2*(10**9)
    while r-l>1:
        m = (l+r)//2
        if f(m)<n:
            l = m
        else:
            r = m

    if f(r) != n:
        print('NO')
        return

    print('YES')
    print(r)

if __name__ == '__main__':
    main()
