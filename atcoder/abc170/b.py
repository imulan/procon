x, y = map(int, input().split())

ans = 'No'
for i in range(x+1):
    k = x-i
    if 2*i+4*k == y:
        ans = 'Yes'

print(ans)
