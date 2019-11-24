def solve():
    n,x,a,b = map(int,input().split())
    if a>b:
        a,b = b,a

    while x>0 and a>1:
        x -= 1
        a -= 1

    while x>0 and b<n:
        x -= 1
        b += 1

    return b-a

def main():
    q = int(input())
    for _ in range(q):
        print(solve())

if __name__ == "__main__":
    main()
