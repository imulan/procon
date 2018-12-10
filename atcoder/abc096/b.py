v = list(map(int,input().split()))
k = int(input())

v.sort()
for _ in range(k):
    v[-1] *= 2
print(sum(v))
