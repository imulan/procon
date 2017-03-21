mod = 10**9+7
ans = 1
for i in range(int(input())):
    ans *= i+1
    ans %= mod
print(ans)
