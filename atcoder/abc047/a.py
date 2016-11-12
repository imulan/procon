x = list(map(int,input().split()))
x.sort()

ans="No"
if x[0]+x[1] == x[2]:
    ans="Yes"
print(ans)
