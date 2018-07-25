def main():
    a,b,c,n = map(int,input().split())

    num = n-(a+b-c)
    if num<=0 or a>n or b>n or c>n or a<c or b<c:
        return -1
    return num

if __name__ == '__main__':
    print(main())
