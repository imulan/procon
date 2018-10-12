a,b,x = map(int,input().split())

ans = 10**10
for i in range(22):
    for j in range(44):
        if i*1000 + j*500 >= x:
            ans = min(ans, a*i+b*j)
print(ans)
