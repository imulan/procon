s = input()
ok, ng = s.count('o'), s.count('x')
for c in s:
    print(100*ok/(ok+ng))
    if c == 'o':
        ok -= 1
    else:
        ng -= 1
