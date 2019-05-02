from fractions import gcd

n = int(input())
a = list(map(int,input().split()))

g = 0
for i in a:
    g = gcd(g,i)
print(g)
