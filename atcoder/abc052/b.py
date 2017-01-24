n = int(input())

ans = 0
x = 0
for c in input():
    x += 1 if c == 'I' else -1
    ans = max(ans, x)

print(ans)
