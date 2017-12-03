x = int(input())

f = 0
t = x
while t>0:
    f += t%10
    t //= 10

print('Yes' if x%f==0 else 'No')
