n = int(input())

ans = 0
if n%2 == 0:
    pre = 0
    for i in range(32,0,-1):
        ct = n//(5**i*2)
        ans += i*(ct-pre)
        pre = ct

print(ans)
