sa = input()
sb = input()
sc = input()

a,b,c = 0,0,0
turn = 'a'
ans = '?'

while True:
    if turn == 'a':
        if a == len(sa):
            ans = 'A'
            break
        turn = sa[a]
        a += 1
    elif turn == 'b':
        if b == len(sb):
            ans = 'B'
            break
        turn = sb[b]
        b += 1
    else:
        if c == len(sc):
            ans = 'C'
            break
        turn = sc[c]
        c += 1

print(ans)
