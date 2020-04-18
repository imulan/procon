def d(n):
    ret = 0
    while n>0:
        n//=10
        ret += 1
    return ret

def main():
    a,b,x = map(int,input().split())

    ok,ng = 0,10**9+1
    while ng-ok > 1:
        n = (ok+ng)//2
        if a*n + b*d(n) <= x:
            ok = n
        else:
            ng = n

    print(ok)

if __name__ == "__main__":
    main()
