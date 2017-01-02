def f(n,x):
    return 0 if n<0 else n//x+1

def main():
    a,b,x = map(int,input().split())
    print(f(b,x) - f(a-1,x))

if __name__ == '__main__':
    main()
