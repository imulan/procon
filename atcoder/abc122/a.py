s = 'ATCG'
b = input()

ans = 0
for i in range(4):
    if b == s[i]:
        ans = i^1
print(s[ans])
