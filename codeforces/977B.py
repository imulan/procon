n = int(input())
s = input()

d = {}
for i in range(n-1):
    t = s[i:i+2]
    if t not in d:
        d[t] = 0
    d[t] += 1

ans = ''
val = 0
for k,v in d.items():
    if val<v:
        ans,val = k,v
print(ans)
