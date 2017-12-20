a,b = map(int,input().split())
ans = 'Possible'
if a%3!=0 and b%3!=0 and (a+b)%3!=0:
    ans = 'Impossible'
print(ans)
