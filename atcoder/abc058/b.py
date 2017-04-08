o = input()
e = input()

ans = ''
for i in range(len(e)):
    ans = ans+o[i]+e[i]

if len(o) > len(e):
    ans = ans+o[-1]

print(ans)
