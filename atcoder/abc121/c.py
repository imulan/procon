def main():
    n,m = map(int,input().split())

    x = []
    for i in range(n):
        a,b = map(int,input().split())
        x.append((a,b))

    ans,ct = 0,0
    for a,b in sorted(x):
        for _ in range(b):
            ans += a
            ct += 1
            if ct == m:
                return ans
    return -1

if __name__ == "__main__":
    print(main())
