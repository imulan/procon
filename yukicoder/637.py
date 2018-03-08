def f(n):
    if n%15 == 0:
        return 8
    if n%3 == 0 or n%5 == 0:
        return 4
    return len(str(n))

def main():
    a = list(map(int,input().split()))
    ans = 0
    for v in a:
        ans += f(v)
    print(ans)

if __name__ == '__main__':
    main()
