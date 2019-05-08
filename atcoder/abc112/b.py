n,T = map(int,input().split())

ans = 'TLE'
for i in range(n):
    c,t = map(int,input().split())
    if t<=T:
        if ans == 'TLE':
            ans = c
        ans = min(ans, c)
print(ans)
