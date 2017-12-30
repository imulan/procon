def main():
    a,b = map(int,input().split())
    s = input()

    if s[a] != '-':
        return 'No'

    for p in [s[0:a],s[a+1:]]:
        for c in p:
            if not c.isdigit():
                return 'No'

    return 'Yes'

if __name__ == '__main__':
    print(main())
