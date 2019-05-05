n = int(input())
x = list(map(int,input().split()))
m = int(input())
a = list(map(int,input().split()))

for i in range(m):
    a[i] -= 1

for i in a:
    if i == n-1:
        x[i] = min(x[i]+1, 2019)
    else:
        x[i] = min(x[i]+1, x[i+1]-1)

for i in x:
    print(i)
