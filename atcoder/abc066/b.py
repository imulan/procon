s = input()

while True:
    s = s[:-1]
    L = len(s)
    if L%2 != 0:
        continue

    ok = True
    for i in range(L//2):
        if s[i] != s[L//2+i]:
            ok = False
    if ok:
        break

print(len(s))
