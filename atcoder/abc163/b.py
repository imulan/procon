n,m = map(int,input().split())
a = list(map(int,input().split()))

sa = sum(a)
print(-1 if n < sa else n-sa)
