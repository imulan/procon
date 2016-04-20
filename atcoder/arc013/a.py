from itertools import *

a=list(map(int,input().split()))
b=list(map(int,input().split()))
b.sort()
ans=0
print(list(permutations(b)))
for v in permutations(b):
    r=1
    for i in range(3):
        r*=a[i]//v[i]
    ans=max(ans,r)
print(ans)
