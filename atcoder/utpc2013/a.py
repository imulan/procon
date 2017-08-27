def f(s):
    ret = []
    for c in s:
        if c == 'B':
            ret.append(2)
        elif c in 'ADOPQR':
            ret.append(1)
        else:
            ret.append(0)
    return ret

def main():
    print('yes' if f(input()) == f('UTPC') else 'no')

if __name__ == '__main__':
    main()
