n,k = map(int,input().split())

ok,ng = 0,k+1
while ng-ok>1:
    mid = (ng+ok)//2

    s = 0
    m = mid
    for i in range(n):
        s += m
        m //= 2
        if m == 0:
            break

    if s <= k:
        ok = mid
    else:
        ng = mid

print(ok)
