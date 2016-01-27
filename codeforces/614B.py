#TLE

import sys

n = int(input())
a = map(int, input().split())

ans = 1

for p in a:
    ans = ans*p

print(ans)
