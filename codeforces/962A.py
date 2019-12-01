def main():
    n = int(input())
    a = list(map(int,input().split()))

    s = sum(a)
    idx,t = 0,0
    while idx<n and 2*t<s:
        t += a[idx]
        idx += 1
    print(idx)

if __name__ == "__main__":
    main()
