def solve():
    n = int(input())
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))

    l,r = 0,n-1
    while l<n:
        if a[l] != b[l]:
            break
        l += 1
    while r>=0:
        if a[r] != b[r]:
            break
        r -= 1

    if l == n:
        return 'YES'

    add = b[l]-a[l]
    if add < 0:
        return 'NO'

    for i in range(l,r+1):
        a[i] += add

    return 'YES' if a==b else 'NO'

def main():
    t = int(input())
    for _ in range(t):
        print(solve())

if __name__ == "__main__":
    main()
