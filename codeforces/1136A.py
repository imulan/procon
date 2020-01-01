def main():
    n = int(input())
    l,r = [],[]
    for i in range(n):
        a,b = map(int,input().split())
        l.append(a)
        r.append(b)
    k = int(input())

    ans = 0
    for i in range(n):
        if l[i] <= k <= r[i]:
            ans = n-i
            break
    print(ans)

if __name__ == "__main__":
    main()
