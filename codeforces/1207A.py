def solve():
    b,p,f = map(int,input().split())
    h,c = map(int,input().split())

    ans = 0
    for i in range(p+1):
        rb = b - 2*i
        if rb < 0:
            break

        ans = max(ans, h*i + c*min(rb//2,f))

    return ans

def main():
    q = int(input())
    for _ in range(q):
        print(solve())

if __name__ == "__main__":
    main()
