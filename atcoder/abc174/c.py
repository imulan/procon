k = int(input())

s = set()
x, ans = 7 % k, 1
while True:
    if x == 0:
        break

    if x in s:
        ans = -1
        break

    s.add(x)
    x = (x*10+7) % k
    ans += 1

print(ans)
