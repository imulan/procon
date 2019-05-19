n,k = map(int,input().split())

ans = 0
for i in range(1,n+1):
    add = 1/n
    v = i
    while v<k:
        v *= 2
        add /= 2
    ans += add

print('%.15f' % ans)
