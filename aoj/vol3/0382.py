n,c = map(int,input().split())
p = list(map(int,input().split()))

m = n+1
s = sum(p)

ans = s//m
if s%m != 0:
    ans += 1

print(ans)
