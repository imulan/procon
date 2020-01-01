def solve():
    x = int(input())

    ans = 0
    if x%2 == 1:
        x -= 3
        ans += 1
    ans += x//2
    return ans

def main():
    t = int(input())
    for i in range(t):
        print(solve())

if __name__ == "__main__":
    main()
