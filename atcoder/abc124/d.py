n,k = map(int,input().split())
s = input()

x = []
idx = 0
b = 1
while idx<n:
    st = idx
    while idx<n and int(s[idx])==b:
        idx += 1
    x.append(idx-st)
    st = idx
    b ^= 1

if b == 1:
    x.append(0)

ans = n
if len(x) > 2*k+1:
    ans = 0

    t = 0
    for i in range(2*k+1):
        t += x[i]
    ans = max(ans, t)

    for i in range(2*k+1, len(x), 2):
        t -= x[i - (2*k+1)]
        t -= x[i+1 - (2*k+1)]
        t += x[i]
        t += x[i+1]
        ans = max(ans, t)

print(ans)
