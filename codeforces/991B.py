def main():
    n = int(input())
    a = list(map(int,input().split()))
    a.sort()

    sa = sum(a)
    if sa*2 >= 9*n:
        return 0

    for i in range(n):
        sa += 5-a[i]
        if sa*2 >= 9*n:
            return i+1

if __name__ == '__main__':
    print(main())
