def main():
    pow = set()
    for i in range(64):
        pow.add(2**i)

    n = int(input())
    for i in range(1,n):
        j = n-i
        if i not in pow and j not in pow:
            print(i,j)
            return

    print(-1)

if __name__ == '__main__':
    main()
