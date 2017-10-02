def main():
    a,b = map(int,input().split())

    n = int(input())
    s,f = [],[]
    for i in range(n):
        ss,ff = map(int,input().split())
        s.append(ss)
        f.append(ff)

    for i in range(n):
        if f[i] <= a or b <= s[i]:
            continue
        else:
            return 1
    return 0

if __name__ == '__main__':
    print(main())
