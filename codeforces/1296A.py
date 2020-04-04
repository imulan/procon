def solve():
    n = int(input())
    a = list(map(int,input().split()))

    if sum(a)%2 == 1:
        return 'YES'

    ct = [0]*2
    for i in a:
        ct[i%2] += 1

    if ct[0] == n or ct[1] == n:
        return 'NO'
    return 'YES'

def main():
    t = int(input())
    for _ in range(t):
        print(solve())

if __name__ == "__main__":
    main()
