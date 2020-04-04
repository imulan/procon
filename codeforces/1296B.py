def solve():
    s = int(input())
    ans = 0
    while s >= 10:
        for i in range(9,0,-1):
            x = 10**i
            if s >= x:
                ans += x
                s -= x
                s += x//10
                break

    return ans+s

def main():
    t = int(input())
    for _ in range(t):
        print(solve())

if __name__ == "__main__":
    main()
