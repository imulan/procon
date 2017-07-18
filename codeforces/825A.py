S = int(input())
s = input().split('0')

ans = ''
for c in s:
    ans += str(len(c))
print(ans)
