def f(h,m):
    return h*60+m

def main():
    a,b = map(int,input().split())
    x,y = map(int,input().split())

    if f(a,b)>=f(x,y):
        return 'Yes'

    for i in range(f(x,y),f(12,0)):
        H,M = i//60,i%60
        H = (H+6)%12
        M = (M+30)%60
        if f(a,b) >= f(H,M):
            return 'Yes'
    return 'No'

if __name__ == '__main__':
    print(main())
