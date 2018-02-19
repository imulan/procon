n,k = map(int,input().split())

x = n // 2
x //= k+1
y = k*x
z = n - (x+y)
print(x,y,z)
