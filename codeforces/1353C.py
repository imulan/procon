def solve():
    n = int(input())
    ans = 0
    for i in range(3, n+1, 2):
        d = (i-1)//2
        num = 4*i-4
        ans += d*num
    return ans


if __name__ == "__main__":
    for _ in range(int(input())):
        print(solve())
