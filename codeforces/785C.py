def sigma(n):
    return n*(n+1)//2

def main():
    n,m = map(int,input().split())

    if n <= m:
        return n

    l,r = m,n+1
    while r-l>1:
        mid = (l+r)//2
        if n - (sigma(mid)-sigma(m)) + (mid-m-1)*m <= 0:
            r = mid
        else:
            l = mid

    return l+1

if __name__ == '__main__':
    print(main())
