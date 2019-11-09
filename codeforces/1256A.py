def solve():
    a,b,n,s = map(int,input().split())
    x = min(a, s//n)
    s -= n*x
    return 'YES' if s<=b else 'NO'

def main():
    q = int(input())
    for _ in range(q):
        print(solve())

if __name__ == "__main__":
    main()
