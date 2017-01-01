def main():
    n = int(input())

    print(n//2)
    if n%2==0:
        for _ in range(n//2-1):
            print(2,end=" ")
        print(2)
    else:
        for _ in range(n//2-1):
            print(2,end=" ")
        print(3)

if __name__ == '__main__':
    main()
