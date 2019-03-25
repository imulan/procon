s = "ACGT"

a = input()
n = len(a)

ans = 0
for i in range(n):
    if a[i] not in s:
        continue

    j = i
    while j<n and a[j] in s:
        j += 1
    ans = max(ans, j-i)

print(ans)
