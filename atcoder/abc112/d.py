def divisor(x):
    ret = []
    i = 1
    while i*i <= x:
        if x%i == 0:
            ret.append(i)
            if x//i != i:
                ret.append(x//i)
        i += 1
    return sorted(ret, reverse=True)

n,m = map(int,input().split())
for g in divisor(m):
    if m//g >= n:
        print(g)
        break
