s = input().split()

while True:
    found = False
    for i in range(len(s)-2):
        if s[i] == 'not' and s[i+1] == 'not' and s[i+2] != 'not':
            found = True
            del s[i:i+2]
            break

    if not found:
        break

print(' '.join(s))
