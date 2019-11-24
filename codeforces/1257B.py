OK,NG = 'YES','NO'

def solve():
    x,y = map(int,input().split())

    if x == 1:
        if y > 1:
            return NG
    elif x <= 3:
        if y > 3:
            return NG

    return OK

def main():
    q = int(input())
    for _ in range(q):
        print(solve())

if __name__ == "__main__":
    main()
