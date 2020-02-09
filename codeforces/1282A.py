def solve():
    a,b,c,r = map(int,input().split())
    a,b = min(a,b),max(a,b)
    L,R = max(a,c-r),min(b,c+r)
    return b-a-max(0,R-L)

def main():
    t = int(input())
    for _ in range(t):
        print(solve())

if __name__ == "__main__":
    main()
