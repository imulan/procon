s = input()
t = input()

n = len(s)

ans = 'No'
for i in range(n):
    ok = True
    for j in range(n):
        if s[j] != t[(i+j)%n]:
            ok = False

    if ok:
        ans = 'Yes'

print(ans)
