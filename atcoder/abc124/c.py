s = input()
n = len(s)
ans = n
for i in range(2):
    t = 0
    for j in range(n):
        v = (i+j)%2
        if v != int(s[j]):
            t += 1
    ans = min(ans, t)
print(ans)
