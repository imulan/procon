s = list(input())
s.sort()

ans = 'Yes'
for i in range(0,3):
    if (s[i] == s[i+1]) ^ (i%2 == 0):
        ans = 'No'

print(ans)
