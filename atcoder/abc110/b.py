N,M,X,Y = map(int,input().split())
x = list(map(int,input().split()))
y = list(map(int,input().split()))

max_x,min_y = max(x),min(y)

ans = ''
for Z in range(X+1,Y+1):
    if max_x < Z and Z <= min_y:
        ans = 'No '

print(ans+'War')
