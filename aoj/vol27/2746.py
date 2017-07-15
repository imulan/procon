def decode(s):
    ret = []
    for line in s.split('/'):
        a = ''
        for c in line:
            if c == 'b':
                a += 'b'
            else:
                a += '.'*(ord(c)-ord('0'))
        ret.append(list(a))
    return ret

def encode(s):
    ret = []
    for line in s:
        x = ''.join(line)
        x = x.split('b')
        a = ''
        for i in range(len(x)-1):
            if len(x[i])>0:
                a += str(len(x[i]))
            a += 'b'

        if len(x[len(x)-1])>0:
            a += str(len(x[len(x)-1]))
        ret.append(a)

    return '/'.join(ret)

def main():
    while True:
        s = input()
        if s == '#':
            break
        a,b,c,d = map(int,input().split())

        f = decode(s)
        f[a-1][b-1] = '.'
        f[c-1][d-1] = 'b'
        print(encode(f))

if __name__ == '__main__':
    main()
