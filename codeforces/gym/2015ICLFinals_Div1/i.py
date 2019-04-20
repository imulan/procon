import sys

def C(n,r):
    if n<r:
        return 0
    if n==0:
        return 0

    if r>n-r:
        r = n-r
    p = 1
    for i in range(1,r+1):
        p = p*(n-i+1)//i

    return p

def calc(n,m):
    R = 0
    while C(R,m)<=n:
        R += 1000

    l,r = 0,R+1
    while r-l>1:
        mid = (l+r)//2
        if C(mid,m) <= n:
            l = mid
        else:
            r = mid
    return l

def test(c):
    lim = 10**16
    i = c
    while True:
        if C(i,c)>lim:
            break
        i += 1
    return i

def main():

    n,m = map(int,input().split())

    # LIM = test(m)
    # print('LIM',LIM)

    ans = []
    for i in range(m,0,-1):
        v = calc(n,i)
        ans.append(v)
        n -= C(v,i)
        # print('v=',v,'i=',i,'C=',C(v,i))

    if n!=0:
        print('!!! n',n)
        sys.exit(-1)

    for i in range(m-1):
        if ans[i] <= ans[i+1]:
            print('!!!de')
            sys.exit(-2)

    print(' '.join(map(str,ans)))

if __name__ == '__main__':
    main()
