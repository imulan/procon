def main():
    n,m = map(int,input().split())
    a = ['' for _ in range(n)]
    b = ['' for _ in range(m)]

    for i in range(n):
        a[i] = input()
    for i in range(m):
        b[i] = input()

    for i in range(n-m+1):
        for j in range(n-m+1):
            same = True
            for y in range(m):
                for x in range(m):
                    if a[i+y][j+x] != b[y][x]:
                        same = False

            if same:
                return 'Yes'

    return 'No'

if __name__ == '__main__':
    print(main())
