from collections import defaultdict

n = int(input())
d = defaultdict(int)

for i in range(1,n+1):
    s = str(i)
    k = (s[0],s[-1])
    d[k] += 1

ans = 0
for i in range(1,n+1):
    s = str(i)
    k = (s[-1],s[0])
    ans += d[k]
print(ans)
