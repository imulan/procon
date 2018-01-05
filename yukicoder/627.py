T = int(input())

x = [0]
for _ in range(T):
    x.append(int(input()))

ans = 'T'
for i in range(T):
    if abs(x[i]-x[i+1]) != 1:
        ans = 'F'
print(ans)