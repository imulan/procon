n = int(input())
x = 10**20
for i in range(5):
    x = min(x, int(input()))
print((n+x-1)//x+4)
