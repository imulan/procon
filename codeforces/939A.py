def main():
    n = int(input())
    f = list(map(int,input().split()))
    for i in range(n):
        f[i] -= 1

    for i in range(n):
        now = i
        for j in range(3):
            now = f[now]
        if now == i:
            return 'YES'

    return 'NO'

if __name__ == '__main__':
    print(main())
