n = int(input())
h = list(map(int,input().split()))

ans = 0
pre = 0
for i in h:
    if pre < i:
        ans += i-pre

    pre = i

print(ans)
