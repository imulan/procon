def main():
    n = int(input())
    if n==0:
        return 0

    ans,up = '',0
    flg = 0
    if n<0:
        flg = 1
        n = -n

    for i in range(40):
        d = (n>>i&1)+up
        if i%2==flg:
            if d==0:
                ans,up = '0'+ans,0
            elif d==1:
                ans,up = '1'+ans,0
            elif d==2:
                ans,up = '0'+ans,1
            else:
                assert(False)
        else:
            if d==0:
                ans,up = '0'+ans,0
            elif d==1:
                ans,up = '1'+ans,1
            elif d==2:
                ans,up = '0'+ans,1
            else:
                assert(False)

    return ans[ans.find('1'):]

if __name__ == '__main__':
    print(main())
