def solve():
    a,b,c,d,k = map(int,input().split())
    for x in range(k+1):
        y = k-x
        if x*c>=a and y*d>=b:
            print(x,y)
            return

    print(-1)

def main():
    t = int(input())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
