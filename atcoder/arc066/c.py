def solve(n,a):
    ct = [0 for _ in range(n)]
    for v in a:
        ct[v] += 1

    if n%2 == 1:
        if ct[0] != 1:
            return 0

        for i in range(1,n):
            if i%2 == 1:
                if ct[i] != 0:
                    return 0
            else:
                if ct[i] != 2:
                    return 0
    else:
        if ct[0] != 0:
            return 0

        for i in range(1,n):
            if i%2 == 1:
                if ct[i] != 2:
                    return 0
            else:
                if ct[i] != 0:
                    return 0

    return 2**(n//2)%(10**9+7)

def main():
    n = int(input())
    a = list(map(int,input().split()))
    print(solve(n,a))

if __name__ == '__main__':
    main()
