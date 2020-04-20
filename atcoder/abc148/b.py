n = int(input())
s,t = input().split()

ans = ''
for i in range(n):
    ans += s[i]+t[i]
print(ans)
