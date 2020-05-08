n, a, b = map(int, input().split())

x = a+b
print(a*(n//x)+min(a, n % x))
