ans = 0
for c in input():
    if c == '0':
        ans += 10
    else:
        ans += int(c)
print(ans)
