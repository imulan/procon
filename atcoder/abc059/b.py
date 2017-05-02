a = int(input())
b = int(input())

ans = 'EQUAL'
if a<b:
    ans = 'LESS'
elif a>b:
    ans = 'GREATER'
print(ans)
