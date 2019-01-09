t1 = int(input())
t2 = int(input())

x = (t2-t1)/2
a = x
for i in range(-2,3):
    t = x + i*180
    if abs(a) > abs(t):
        a = t

ans = t1+a
while ans < 0:
    ans += 360
while ans > 360:
    ans -= 360

print(ans)
