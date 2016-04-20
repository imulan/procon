while True:
    n,k=map(int,input().split())
    if n==0:
        break
    x=list(map(int,input().split()))
    x.sort()

    ans=0
    for i in range(k):
        ans+=x[i]
    print(ans)
