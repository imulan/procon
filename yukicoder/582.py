def main():
    n = int(input())
    c = list(map(int,input().split()))

    x,y = 0,0
    for v in c:
        if v == 1:
            x += 1
        elif v == 2:
            y += 1
        elif v > 2:
            return 'B'

    if y <= 1:
        num = x+2*y
        if num%2 == 1:
            return 'A'
    return 'B'

if __name__ == '__main__':
    print(main())