s = input()
k = int(input())

one = 0
while one<len(s) and s[one]=='1':
    one += 1

ans = '1'
if k > one:
    ans = s[one]
print(ans)
