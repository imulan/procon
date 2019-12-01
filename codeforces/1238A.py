def solve():
    x,y = map(int,input().split())
    ans = 'YES'
    if x-y == 1:
        ans = 'NO'
    return ans

def main():
    T = int(input())
    for _ in range(T):
        print(solve())

if __name__ == "__main__":
    main()
