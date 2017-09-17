def f(h,r):
    ret = r+h
    if ret != 0:
        ret //= abs(ret)
    return ret

def main():
    h,r = map(int,input().split())
    print(f(h,r))

if __name__ == '__main__':
    main()
