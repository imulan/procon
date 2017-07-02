a,b = map(int,input().split())
m = min(a,b)
ans = 1
for i in range(1,m+1):
    ans *= i
print(ans)
