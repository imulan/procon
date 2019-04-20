def f(n):
    r = 1
    for i in range(1,n+1):
        r *= i
    return r

def C(n,m):
    return f(n)//f(m)//f(n-m)

def ct2(t):
    r = 0
    n = t
    while n%2==0:
        n//=2
        r += 1
    return r

def main():
    for i in range(3,100000,2):
        print('i=',i,' ct2=',ct2(i+1),end='')
        found = False
        for j in range(2,i//2,2):
            if C(i,j)%2==0:
                print(' ', j)
                found = True
                break

        if not found:
            print(' !!!!!!!!',i+1)




if __name__ == '__main__':
    main()
