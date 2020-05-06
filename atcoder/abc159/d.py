n = int(input())
a = list(map(int, input().split()))

ct = [0]*(n+1)
for i in a:
    ct[i] += 1

x, y = [0]*(n+1), [0]*(n+1)
for i in range(n+1):
    x[i] = ct[i]*(ct[i]-1)//2
    y[i] = (ct[i]-1)*(ct[i]-2)//2
s = sum(x)

for i in a:
    print(s-x[i]+y[i])
