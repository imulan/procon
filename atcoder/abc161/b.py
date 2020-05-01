n, m = map(int, input().split())

a = list(map(int, input().split()))
a.sort()
a.reverse()

# a[m-1] >= sum(a)/4m
print('Yes' if a[m-1]*4*m >= sum(a) else 'No')
