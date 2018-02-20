def main():
    n = int(input())
    a = list(map(int,input().split()))

    m = int(input())
    x = []
    for _ in range(m):
        l,r = map(int,input().split())
        x.append((l,r))

    sa = sum(a)

    for i in range(m):
        if x[i][0] <= sa <= x[i][1]:
            return sa
        if sa <= x[i][0]:
            return x[i][0]

    return -1

if __name__ == '__main__':
    print(main())
