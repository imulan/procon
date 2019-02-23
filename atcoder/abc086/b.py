a,b = input().split()
n = int(a+b)

ans = 'No'
for i in range(1000):
    if i*i == n:
        ans = 'Yes'
print(ans)
