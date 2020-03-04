a,b,c,n = map(int,input().split())
x = list(map(int,input().split()))
print('Yes' if 10000*a+5000*b+1000*c >= sum(x) else 'No')
