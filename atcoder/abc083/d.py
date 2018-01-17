def calc(s):
    n = len(s)

    dec = [0 for i in range(n)]
    inc = [0 for i in range(n)]
    ran = [0 for i in range(n)]

    for i in range(n):
        dec[i] = n-1-i
        inc[i] = i

    i = 0
    while i<n:
        if s[i] == '0':
            i += 1
        else:
            st = i
            while i<n and s[i]=='1':
                i += 1
            for j in range(st,i):
                ran[j] = i-st

    ans = n
    for i in range(n):
        v = max(dec[i],inc[i],ran[i])
        if s[i] == '1':
            ans = min(ans,v)
    return ans

def main():
    s = input()
    n = len(s)

    t = list(s[:])
    for i in range(n):
        if t[i] == '0':
            t[i] = '1'
        else:
            t[i] = '0'
    t = ''.join(t)

    return max(calc(s),calc(t))

if __name__ == '__main__':
    print(main())
