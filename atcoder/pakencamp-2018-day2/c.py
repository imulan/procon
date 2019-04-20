def main():
    n = int(input())
    a = list(map(int,input().split()))

    for i in range(1,n+1):
        valid = True
        for j in range(i):
            idx = j
            s = set()
            while idx<n:
                if a[idx] != 0:
                    s.add(a[idx])
                idx += i

            if len(s) > 1:
                valid = False
                break

        if valid:
            return i

if __name__ == "__main__":
    print(main())
