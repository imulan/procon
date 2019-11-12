n,k = map(int,input().split())
s = input()

ct = 0
for i in range(1,n):
    if s[i-1] != s[i]:
        ct += 1

ct -= min(ct,2*k)
print(n-ct-1)
