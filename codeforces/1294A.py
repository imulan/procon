def solve():
    a,b,c,n = map(int,input().split())

    s = a+b+c+n
    if s%3 != 0 or max(a,b,c) > s//3:
        return 'NO'
    return 'YES'

def main():
    t = int(input())
    for _ in range(t):
        print(solve())

if __name__ == "__main__":
    main()
