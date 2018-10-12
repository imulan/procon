def digit_sum(x):
    ret = 0
    for c in str(x):
        ret += int(c)
    return ret

def main():
    a,n,m = map(int,input().split())

    ans = 0
    y = 0
    while True:
        x = (y+a)**n
        if x > m:
            break

        if x>0 and digit_sum(x) == y:
            ans += 1

        y += 1

    print(ans)

if __name__ == '__main__':
    main()
