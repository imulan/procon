n = int(input())
ans = 0
for i in range(1,n+1,2):
    ct = 0
    for j in range(1,i+1):
        if i%j==0:
            ct += 1

    if ct == 8:
        ans += 1
print(ans)
