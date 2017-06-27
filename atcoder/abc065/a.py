x,a,b = map(int,input().split())

y = a-b
ans = 'delicious'
if y < 0:
    if y >= -x:
        ans = 'safe'
    else:
        ans = 'dangerous'

print(ans)
