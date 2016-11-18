def f(n,k):
    return 50*n + (int)(50*n/(0.8+0.2*k))

a,b=map(int,input().split())
print(f(a,b))
