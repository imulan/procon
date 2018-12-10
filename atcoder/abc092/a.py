v = [int(input()) for i in range(4)]
ans = 0
for i in range(0,4,2):
    ans += min(v[i],v[i+1])
print(ans)
