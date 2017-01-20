sx,sy,tx,ty = map(int,input().split())

ans = ''

# 1周目
ans += 'D'
for _ in range(tx-sx+1):
    ans += 'R'
for _ in range(ty-sy+1):
    ans += 'U'
for _ in range(tx-sx+1):
    ans += 'L'
for _ in range(ty-sy):
    ans += 'D'

# 2周目
for _ in range(tx-sx):
    ans += 'R'
for _ in range(ty-sy+1):
    ans += 'U'
for _ in range(tx-sx+1):
    ans += 'L'
for _ in range(ty-sy+1):
    ans += 'D'
ans += 'R'

print(ans)
