n = int(input())
ans = (n+1)//2
if n%2 == 0:
    ans = n+1
    if n == 0:
        ans = 0
print(ans)
