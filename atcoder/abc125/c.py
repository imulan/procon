def divisor(x):
    i = 1
    d = []
    while i*i <= x:
        if x%i == 0:
            d.append(i)
            d.append(x//i)
        i += 1
    return d

n = int(input())
a = sorted(list(map(int,input().split())))

ans = 1
for i in range(2):
    for d in divisor(a[i]):
        ct = 0
        for j in a:
            if j%d == 0:
                ct += 1
        if ct >= n-1:
            ans = max(ans, d)

print(ans)
