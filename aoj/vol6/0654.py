n = int(input())
s = input()

i = 0
ans = 0
while i+1 < n:
    if s[i:i+2] in ['OX','XO']:
        i += 2
        ans += 1
    else:
        i += 1
print(ans)
