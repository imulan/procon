def main():
    n,a = map(int,input().split())
    a -= 1
    t = list(map(int,input().split()))

    ans = 0
    if t[a] == 1:
        ans = 1

    for i in range(1,100):
        add = 0
        outrange = False

        x = a-i
        if 0 <= x < n:
            if t[x] == 1:
                add += 1
        else:
            outrange = True

        x = a+i
        if 0 <= x < n:
            if t[x] == 1:
                add += 1
        else:
            outrange = True

        if add == 2 or (add == 1 and outrange):
            ans += add

    print(ans)

if __name__ == '__main__':
    main()
