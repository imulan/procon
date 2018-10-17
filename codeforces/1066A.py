def solve():
    L,v,l,r = map(int,input().split())

    n = L//v
    n -= r//v
    n += (l-1)//v
    return n

def main():
    t = int(input())
    for _ in range(t):
        print(solve())

if __name__ == '__main__':
    main()
