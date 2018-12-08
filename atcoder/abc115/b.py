n = int(input())

s,mx = 0,0
for i in range(n):
    p = int(input())
    mx = max(mx,p)
    s += p

s -= mx//2
print(s)
