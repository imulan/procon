# TLE...

def main():
    s = input()
    S = len(s)

    suf = [0 for i in range(S+1)]
    for i in range(S-1, -1, -1):
        suf[S-i] = suf[S-i-1] + int(s[i])*(10**(S-i-1))

    pw = [1 for i in range(S+1)]
    for i in range(1,S+1):
        pw[i] = pw[i-1]*10

    a = 0
    ba0 = int(s[1:S-1])
    ba1 = -1
    if S>3:
        ba1 = int(s[1:S-2])

    bb0 = int(s[1:1+(S-1)//2+1])
    bb1 = -1
    if S>3:
        bb1 = int(s[1:1+(S-1)//2])

    for i in range(S):
        a = a*10 + int(s[i])
        # aの桁数
        A = i+1

        # aの桁数が支配的になる場合
        for y in [A,A+1]:
            x = S-y
            # bがなくなるのでNG
            if i+1 > x-1:
                continue

            C = S-x
            c = suf[C]

            B = x - (i+1)
            if y == A:
                b = ba0
            else:
                b = ba1

            # print('CHECK',a,b,c)

            # no leading zeros
            if (A>1 and s[0]=='0') or (B>1 and s[i+1]=='0') or (C>1 and s[x]=='0'):
                continue
            # correct
            if a+b == c:
                return a,b,c

        # update ba
        if S-2*A-1 >= 0:
            ba0 = ba0%pw[S-2*A-1]
            ba0 //= 10
        if S-2*A-2 >= 0:
            ba1 = ba1%pw[S-2*A-2]
            ba1 //= 10

        # bの桁数が支配的になる場合
        L = S-1-i
        if L<2:
            continue
        for B in [(L+1)//2-1, (L+1)//2]:
            if B<=0:
                continue

            C = S-A-B
            c = suf[C]

            if B == (L+1)//2:
                b = bb0
            else:
                b = bb1

            # print('CHECK',a,b,c)

            # no leading zeros
            if (A>1 and s[0]=='0') or (B>1 and s[i+1]=='0') or (C>1 and s[S-C]=='0'):
                continue
            # correct
            if a+b == c:
                return a,b,c

        # update bb
        if L//2-1 >= 0:
            bb0 = bb0%pw[L//2-1]
            if L%2 == 1:
                bb0 = bb0*10+int(s[A+L//2])
        if L//2-2 >= 0:
            bb1 = bb1%pw[L//2-2]
            if L%2 == 1:
                bb1 = bb1*10+int(s[A+L//2])

    assert False, 'Not found'

if __name__ == '__main__':
    a,b,c = main()
    print(str(a)+'+'+str(b)+'='+str(c))
