n = int(input())
s = ''

if n==0:
    s = '0'
else:
    while n>0:
        s = str(n%7) + s
        n //= 7
print(s)
