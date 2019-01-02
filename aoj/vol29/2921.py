n = map(int,input().split())
a = list(map(int,input().split()))

ok,ng = 1,10000
while ng-ok > 1:
    mid = (ok+ng)//2

    valid = True
    now = 0
    for i in a:
        now += i
        now -= mid
        if now < 0:
            valid = False

    if valid:
        ok = mid
    else:
        ng = mid

print(ok)
