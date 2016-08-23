ans = 0
for i in range(100):
    if (i+1)%3 != 0 and (i+1)%5 != 0:
        ans += i+1
print(ans)
