t=int(input())
pw=[2**x for x in range(31)]

for T in range(t):
    n=int(input())
    s=n*(n+1)//2

    p=0
    while pw[p]<=n:
        s-=pw[p]*2
        p+=1
    print(s)
