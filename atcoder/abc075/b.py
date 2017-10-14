h,w = map(int,input().split())
s = []
for _ in range(h):
    s.append(list(input()))

for i in range(h):
    for j in range(w):
        if s[i][j]=='#':
            continue

        v = 0
        for dy in range(-1,2):
            for dx in range(-1,2):
                ny,nx = i+dy,j+dx
                if 0<=ny<h and 0<=nx<w and s[ny][nx]=='#':
                    v += 1
        s[i][j] = str(v)

for i in range(h):
    print(''.join(s[i]))
