INF = 10**10

def solve():
    n,x,y,d = map(int,input().split())

    ans = INF
    if abs(y-x)%d == 0:
        ans = min(ans, abs(y-x)//d)
    if (n-y)%d == 0:
        t = (n-x+d-1)//d
        t += (n-y)//d
        ans = min(ans, t)
    if (y-1)%d == 0:
        t = (x-1+d-1)//d
        t += (y-1)//d
        ans = min(ans, t)

    if ans == INF:
        ans = -1
    return ans

def main():
    t = int(input())
    for i in range(t):
        print(solve())

if __name__ == "__main__":
    main()
