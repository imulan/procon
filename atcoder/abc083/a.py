a,b,c,d = map(int,input().split())
l,r = a+b,c+d

ans = 'Balanced'
if l<r:
    ans = 'Right'
elif l>r:
    ans = 'Left'
print(ans)
