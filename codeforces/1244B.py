def solve():
    n = int(input())
    s = input()

    ans = n
    for i in range(n):
        if s[i]=='1':
            d = max(i+1, n-i)
            ans = max(ans, 2*d)

    return ans

def main():
    t = int(input())
    for _ in range(t):
        print(solve())

if __name__ == "__main__":
    main()
