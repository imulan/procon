def main():
    n = int(input())
    a = list(map(int,input().split()))

    x = [0,0,3,4]

    ans = 0
    for i in range(1,n):
        if a[i-1]+a[i] == 5:
            print('Infinite')
            return

        if a[i] == 1:
            ans += x[a[i-1]]
        else:
            ans += x[a[i]]
            if i>=2 and a[i]==2 and a[i-2]==3:
                ans -= 1

    print('Finite')
    print(ans)

if __name__ == "__main__":
    main()
