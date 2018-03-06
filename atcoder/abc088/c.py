def main():
    c = []
    for i in range(3):
        c.append(list(map(int,input().split())))

    a = [0 for _ in range(3)]
    b = [0 for _ in range(3)]

    for val in range(-200, 201):
        a[0] = val
        b[0] = c[0][0] - a[0]

        a[1] = c[1][0] - b[0]
        a[2] = c[2][0] - b[0]
        b[1] = c[0][1] - a[0]
        b[2] = c[0][2] - a[0]

        ok = True
        for i in range(3):
            for j in range(3):
                if a[i]+b[j] != c[i][j]:
                    ok = False
        if ok:
            return 'Yes'

    return 'No'

if __name__ == '__main__':
    print(main())
