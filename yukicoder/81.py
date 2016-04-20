from decimal import *

n = int(input())
a = [Decimal(input()) for i in range(n)]

ans=Decimal(0)

for v in a:
    ans = ans+v

print("{0:.10f}".format(ans))
