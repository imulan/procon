def main():
    n,k = map(int,input().split())

    ans = min(k-1, n-k)
    ans += n-1
    ans += n+n+1
    print(ans)

if __name__ == "__main__":
    main()
