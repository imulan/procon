a,b = map(int,input().split())

ans = b-a
if b%a == 0:
    ans = a+b
print(ans)
