n = int(input())
d,x = map(int,input().split())

ans = x
for _ in range(n):
    a = int(input())
    # y*a+1 <= d
    y = (d-1)//a
    ans += y+1

print(ans)
