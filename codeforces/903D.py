import collections

def main():
    n = int(input())
    a = list(map(int, input().split()))

    ans = 0
    x = 0
    ct = collections.defaultdict(int)
    for i in range(n):
        x += a[i]
        ct[a[i]] += 1

        mul = i+1
        sub = x
        for j in range(-1,2):
            if a[i]+j in ct:
                num = ct[a[i]+j]
                mul -= num
                sub -= num*(a[i]+j)

        ans += a[i]*mul
        ans -= sub

    print(ans)

if __name__ == '__main__':
    main()
