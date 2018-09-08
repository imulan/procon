n = int(input())
w = []
for i in range(n):
    w.append(input())

ans = 'Yes'
s = []
s.append(w[0])
for i in range(1,n):
    if w[i-1][-1] != w[i][0]:
        ans = 'No'
    if w[i] in s:
        ans = 'No'
    s.append(w[i])

print(ans)
