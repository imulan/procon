x,y = input().split()

ans = '='
if x < y:
    ans = '<'
if x > y:
    ans = '>'
print(ans)
