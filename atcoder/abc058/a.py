a,b,c = map(int,input().split())

l = min(a,b,c)
r = max(a,b,c)
m = a+b+c-l-r

print('YES' if m-l == r-m else 'NO')
