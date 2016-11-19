import fractions

a,b=map(int,input().split())
print(fractions.gcd(a+b,a*b))
