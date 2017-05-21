def solve():
    n,x = map(int,input().split())

    ans = n%x
    if n%x == 0:
        ans = x

    print(ans)

def main():
    for _ in range(int(input())):
        solve()

if __name__ == '__main__':
    main()
