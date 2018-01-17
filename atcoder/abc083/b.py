n,a,b = map(int,input().split())

ans = 0
for i in range(1,n+1):
    s = 0
    t = i
    while t>0:
        s += t%10
        t = t//10

    if a <= s <= b:
        ans += i
print(ans)
