n = int(input())
a = list(map(int,input().split()))

o = []
ans = 0
for i in a:
    if i%2==1:
        o.append(i)
    else:
        ans += i//2

o.sort()
o.reverse()

for i in range(0,len(o)-1,2):
    b = o[i]+o[i+1]
    ans += b//2

print(ans)
