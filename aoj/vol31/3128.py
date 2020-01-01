n = int(input())
a = list(map(int,input().split()))

ans = 1
prev = a[0]
for i in range(1,n):
    if prev >= a[i]:
        ans += 1
    prev = a[i]

print(ans)
print(n)
