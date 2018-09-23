def main():
    s = input()
    t = input()

    n = len(s)
    ds,dt = {},{}

    for i in range(n):
        if s[i] in ds:
            if ds[s[i]] != t[i]:
                return 'No'
        else:
            ds[s[i]] = t[i]

        if t[i] in dt:
            if dt[t[i]] != s[i]:
                return 'No'
        else:
            dt[t[i]] = s[i]

    return 'Yes'

if __name__ == '__main__':
    print(main())
