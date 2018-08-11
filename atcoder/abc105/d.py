import collections

n,m = map(int,input().split())
a = list(map(int,input().split()))

s = 0
ct = collections.defaultdict(int)
for i in range(n):
    s += a[i]
    ct[s%m] += 1

s = 0
ans = 0
for i in range(n):
    ans += ct[s%m]
    s += a[i]
    ct[s%m] -= 1

print(ans)
