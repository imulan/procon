n = int(input())
t,a = map(int,input().split())
h = list(map(int,input().split()))

a *= 1000
t *= 1000

d = abs(t - h[0]*6 - a)
ans = 0
for i in range(n):
    td = abs(t - h[i]*6 - a)
    if td < d:
        d = td
        ans = i

print(ans + 1)
