def solve():
    a,b = map(int,input().split())
    if a==b:
        return 0

    if a<b and (b-a)%2==1:
        return 1
    if a>b and (a-b)%2==0:
        return 1

    return 2

def main():
    t = int(input())
    for _ in range(t):
        print(solve())

if __name__ == "__main__":
    main()
