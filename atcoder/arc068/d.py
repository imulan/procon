def main():
    n = int(input())
    a = set(map(int,input().split()))

    L = len(a)
    if L%2 == 0:
        L -= 1

    return L

if __name__ == '__main__':
    print(main())
