def main():
    n,k = map(int,input().split())
    a = list(map(int,input().split()))

    rem = 10**19
    id,num = -1,-1
    for i in range(k):
        t = n//a[i]
        tr = n - a[i]*t
        if rem > tr:
            rem = tr
            id = i+1
            num = t

    print(id,num)

if __name__ == '__main__':
    main()
