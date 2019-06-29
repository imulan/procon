n = int(input())
p = list(map(int,input().split()))

ans = 0
for i in range(1,n-1):
    if p[i] != max(p[i-1:i+2]) and p[i] != min(p[i-1:i+2]):
        ans += 1

print(ans)
