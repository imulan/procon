h,w = map(int,input().split())
a = []
for i in range(h):
    a.append(list(map(int,input().split())))

ans = []
for i in range(h):
    x = list(range(0,w))
    if i%2 == 1:
        x.reverse()
    for j in range(w-1):
        if a[i][x[j]]%2 == 1:
            a[i][x[j]] -= 1
            a[i][x[j+1]] += 1
            ans.append([i+1, x[j]+1, i+1, x[j+1]+1])

    if i < h-1:
        if a[i][x[-1]]%2 == 1:
            a[i][x[-1]] -= 1
            a[i+1][x[-1]] += 1
            ans.append([i+1, x[-1]+1, i+1+1, x[-1]+1])

print(len(ans))
for l in ans:
    print(' '.join(map(str,l)))
