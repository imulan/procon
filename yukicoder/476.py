def main():
    n,a = map(int,input().split())
    x = list(map(int,input().split()))

    X = sum(x)
    return 'YES' if X % n == 0 and X // n == a else 'NO'

if __name__ == '__main__':
    print(main())
