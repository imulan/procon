n = int(input())
ans = 'No'
for i in range(100):
    for j in range(100):
        if i*4 + j*7 == n:
            ans = 'Yes'
print(ans)
