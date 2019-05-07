ans = 0
loss = 0
for i in range(5):
    x = int(input())
    if x%10 != 0:
        loss = max(loss, 10-x%10)
    ans += (x+9)//10*10
print(ans - loss)
