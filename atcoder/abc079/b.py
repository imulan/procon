def main():
    n = 90
    a = [0 for i in range(n)]
    a[0],a[1] = 2,1

    for i in range(2,n):
        a[i] = a[i-1]+a[i-2]

    print(a[int(input())])

if __name__ == '__main__':
    main()
