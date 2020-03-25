N = 10**5 + 3

def main():
    n,p,w,d = map(int,input().split())

    x_max = p//w
    for i in range(N):
        x = x_max-i
        if x<0:
            break

        rem = p-x*w
        if rem%d == 0:
            y = rem//d
            if x+y <= n:
                z = n-x-y
                print(x,y,z)
                return

    print(-1)

if __name__ == "__main__":
    main()
