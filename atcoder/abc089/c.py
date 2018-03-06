import itertools

n = int(input())

T = 'MARCH'
ct = [0 for _ in range(5)]
for _ in range(n):
    s = input()
    if s[0] not in T:
        continue
    ct[T.find(s[0])] += 1

ans = 0
for x,y,z in itertools.combinations(ct,3):
    ans += x*y*z
print(ans)
