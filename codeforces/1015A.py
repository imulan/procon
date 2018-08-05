n,m = map(int,input().split())

x = [0 for _ in range(m+1)]
for i in range(n):
    l,r = map(int,input().split())
    for j in range(l,r+1):
        x[j] = 1

ans = []
for i in range(1,m+1):
    if x[i] == 0:
        ans.append(i)

print(len(ans))
print(' '.join(map(str,ans)))
