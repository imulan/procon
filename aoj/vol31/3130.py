n = int(input())
a,b = map(int,input().split())

n %= 12
for i in range(n):
    if i%2 == 0:
        a = a-b
    else:
        b = a+b
print(a,b)
