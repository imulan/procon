def main():
    t = int(input())
    for _ in range(t):
        n,x,y = map(int,input().split())

        a,b = 1,n
        if x+y < n+1:
            b = x+y-1
        else:
            a = min(n,x+y+1-n)
        print(a,b)

if __name__ == "__main__":
    main()
