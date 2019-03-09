def f(n):
    ret = 0
    for i in range(40):
        mod = 2**(i+1)

        num = n//mod
        rem = n%mod

        ct = num*(mod//2)
        ct += max(0, rem - mod//2 + 1)
        if ct%2 == 1:
            ret |= (1<<i)

    return ret

def main():
    a,b = map(int,input().split())
    if a > 0:
        a -= 1
    return f(b)^f(a)

if __name__ == "__main__":
    print(main())
