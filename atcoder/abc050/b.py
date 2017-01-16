n = int(input())
t = list(map(int,input().split()))
m = int(input())

T = 0
for v in t:
    T += v

for i in range(m):
    p,x = map(int,input().split())
    p -= 1
    print(T-t[p]+x)
