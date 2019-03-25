n,q = map(int,input().split())
s = input()

a = [0 for i in range(n+1)]
for i in range(n-1):
    if s[i:i+2] == 'AC':
        a[i+1] = 1

for i in range(n):
    a[i+1] += a[i]

for i in range(q):
    l,r = map(int,input().split())
    print(a[r-1] - a[l-1])
