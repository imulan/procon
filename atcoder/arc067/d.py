def main():
    N,A,B = map(int,input().split())
    X = list(map(int,input().split()))

    ans = 0
    for i in range(N-1):
        d = X[i+1]-X[i]
        ans += min(B, A*d)

    print(ans)

if __name__ == '__main__':
    main()
