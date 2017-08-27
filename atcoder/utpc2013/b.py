def f(y,m):
    return 12*y+m

def s(x):
    return x*(x+1)//2

def main():
    y,m = map(int,input().split())

    p = f(y,m) - f(2013,12);

    if p<=1:
        print(2013,12+p)
        return

    p -= 1

    l,r = 14,100000000000
    while r-l>1:
        mid = (l+r)//2;
        if s(mid)-s(13)<p:
            l = mid
        else:
            r = mid

    p -= (s(l)-s(13));
    print(l+2001,p)

if __name__ == '__main__':
    main()
