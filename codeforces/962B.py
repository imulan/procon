def main():
    n,a,b = map(int,input().split())
    s = list(filter(lambda x:x>0, map(len, input().split('*'))))

    x = a+b
    for w in s:
        if a>b:
            a,b = b,a

        ma,mb = w//2,(w+1)//2
        a,b = max(0,a-ma), max(0,b-mb)

    print(x-a-b)

if __name__ == "__main__":
    main()
