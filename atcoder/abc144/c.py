n = int(input())

ans = n
for i in range(1,10**6+1):
    if n%i == 0:
        j = n//i
        ans = min(ans, i-1+j-1)
print(ans)
