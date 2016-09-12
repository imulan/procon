import math

a,b = map(int,input().split())
if a > b:
    a,b = b,a

ans = math.sqrt(a*a + b*b)
if b > a:
    ans = math.sqrt(b*b - a*a)
print(ans)
