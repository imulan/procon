def main():
    n = int(input())
    s = input().split()
    t = input().split()

    for i in range(n):
        if s[i]!=t[i]:
            print(i+1)
            print(s[i])
            print(t[i])

if __name__ == '__main__':
    main()
