def solve():
    n = int(input())
    a = sorted(list(map(int, input().split())))
    for i in range(n-1):
        if a[i+1]-a[i] == 1:
            return 2
    return 1

def main():
    q = int(input())
    for _ in range(q):
        print(solve())

if __name__ == "__main__":
    main()
