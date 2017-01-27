def main():
    n,k = map(int,input().split())

    if n <= k:
        return 1

    return n//(k+1) + 1


if __name__ == '__main__':
    print(main())
