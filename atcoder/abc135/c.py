n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))

ans = 0
for i in range(n):
    for j in range(i,i+2):
        if a[j]>0:
            x = min(a[j],b[i])
            b[i] -= x
            a[j] -= x
            ans += x

print(ans)
