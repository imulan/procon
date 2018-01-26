def main():
    s = input()
    n = int(s)
    if n<10:
        return 1

    m = int(s[0])+1
    m *= 10**(len(s)-1)
    return m-int(n)

if __name__ == '__main__':
    print(main())
