n = int(input())
a = list(map(int,input().split()))

x = [0]*2
for i in a:
    x[i%2] += 1
print(min(x))
