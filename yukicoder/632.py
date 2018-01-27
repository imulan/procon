def is_kadomatsu(l):
    c = list(map(int,l))
    if c[0]==c[1] or c[1]==c[2] or c[0]==c[2]:
        return False

    return c[1]==max(c) or c[1]==min(c)

def main():
    c = list(input().split())
    idx = c.index('?')

    ans = ''
    for n in '14':
        c[idx] = n
        if is_kadomatsu(c):
            ans += n
    print(ans)

if __name__ == '__main__':
    main()
