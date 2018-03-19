def main():
    n,d = map(int,input().split())
    x = list(map(int,input().split()))
    x.sort()

    ans = n
    for i in range(n):
        j = i
        while j<n and x[j]-x[i]<=d:
            j += 1
        ans = min(ans, n-(j-i))

    print(ans)

if __name__ == '__main__':
    main()
