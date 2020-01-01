m,n = map(int,input().split())
a = list(map(int,input().split()))

if m == 2:
    ans = n
    for i in range(2):
        t = 0
        for j in range(n):
            idx = (i+j)%2 + 1
            if idx != a[j]:
                t += 1
        ans = min(ans, t)
else:
    ans = 0
    prev = a[0]
    for i in range(1,n):
        if prev == a[i]:
            ans += 1
            a[i] = -1
        prev = a[i]

print(ans)
