def solve():
    x,y,z = sorted(list(map(int,input().split())))

    if x+z <= y:
        x += z
    else:
        d = y-x

        z -= d
        x += d

        z //= 2
        x += z
        y += z

    return x

q = int(input())
for _ in range(q):
    print(solve())
