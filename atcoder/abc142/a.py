def main():
    n = int(input())
    ct = 0
    for i in range(1,n+1):
        ct += i%2
    ans = ct/n
    print('{:.15f}'.format(ans))

if __name__ == "__main__":
    main()
