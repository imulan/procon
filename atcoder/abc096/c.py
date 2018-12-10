h,w = map(int,input().split())
s = []
for i in range(h):
    s.append(input())

ans = 'Yes'
for i in range(h):
    for j in range(w):
        if s[i][j] != '#':
            continue

        bl = False
        for dy,dx in [(-1,0),(1,0),(0,-1),(0,1)]:
            y,x = i+dy,j+dx
            if 0<=y<h and 0<=x<w and s[y][x]=='#':
                bl = True

        if not bl:
            ans = 'No'

print(ans)
