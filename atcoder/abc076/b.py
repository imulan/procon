n = int(input())
k = int(input())

ans = 2**20
for mask in range(1<<n):
    t = 1
    for i in range(n):
        if (mask>>i)&1:
            t *= 2
        else:
            t += k
    ans = min(ans,t)

print(ans)
