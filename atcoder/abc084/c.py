n = int(input())
c,s,f = [[0 for i in range(n-1)] for j in range(3)]
for i in range(n-1):
    c[i],s[i],f[i] = map(int,input().split())

for i in range(n):
    ans = 0
    for j in range(i,n-1):
        if ans < s[j]:
            ans = s[j]
        else:
            if ans%f[j] != 0:
                ans += f[j]-ans%f[j]
        ans += c[j]
    print(ans)
