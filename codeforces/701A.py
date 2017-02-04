def main():
    n = int(input())
    a = list(map(int,input().split()))

    each = sum(a)*2//n

    used = [False for _ in range(n)]

    for i in range(n):
        if used[i]:
            continue

        for j in range(i+1,n):
            if used[j]:
                continue

            if a[i]+a[j] == each:
                used[i] = True
                used[j] = True
                print(i+1,j+1)
                break

if __name__ == '__main__':
    main()
