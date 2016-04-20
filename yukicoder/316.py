def gcd(x,y):
    if x<y :
        x,y=y,x

    while y!=0:
        x,y=y,x%y

    return x

def lcm(x,y):
    return x*y//gcd(x,y)

def solve():
    n=int(input())
    a,b,c=map(int,input().split())

    ct_a=n//a
    ct_b=n//b
    ct_c=n//c

    ct_ab=n//lcm(a,b)
    ct_bc=n//lcm(b,c)
    ct_ca=n//lcm(c,a)

    ct_abc=n//lcm(a,lcm(b,c))

    print(ct_a+ct_b+ct_c-ct_ab-ct_bc-ct_ca+ct_abc)

if __name__ == "__main__":
    solve()
