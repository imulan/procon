n = int(input())
a = 0
for _ in range(n):
    l,r = map(int,input().split())
    a += r-l+1
print(a)
