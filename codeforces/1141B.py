n = int(input())
a = list(map(int,input().split()))

n *= 2
a.extend(a)

ans = 0
i = 0
while i<n:
    if a[i] == 0:
        i += 1
        continue

    j = i
    while j<n and a[j]==1:
        j += 1
    ans = max(ans,j-i)
    i = j

print(ans)
