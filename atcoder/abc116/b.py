def f(n):
    if n%2 == 0:
        return n//2
    return 3*n+1

s = int(input())
ans = 1
used = set()
while True:
    if s in used:
        break

    used.add(s)
    ans += 1
    s = f(s)
print(ans)
