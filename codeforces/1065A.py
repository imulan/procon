def solve():
    s,a,b,c = map(int,input().split())

    x = s//(a*c)
    ans = x*(a+b)
    s -= x*a*c
    ans += s//c

    return ans

def main():
    n = int(input())
    for i in range(n):
        print(solve())

if __name__ == "__main__":
    main()
