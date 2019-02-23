c = [500,100,50]
a = []
for i in range(3):
    a.append(int(input()))
x = int(input())

def dfs(d,y):
    if d == 3:
        if y == x:
            return 1
        return 0

    ret = 0
    for i in range(a[d]+1):
        ret += dfs(d+1, y+c[d]*i)
    return ret

print(dfs(0,0))
