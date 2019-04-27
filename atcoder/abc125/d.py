n = int(input())
a = list(map(int,input().split()))

neg = 0
for i in a:
    if i<0:
        neg += 1

a = sorted(list(map(abs,a)))
ans = sum(a)
if neg%2 == 1:
    ans -= 2*a[0]
print(ans)
