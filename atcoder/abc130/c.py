w,h,x,y = map(int,input().split())

s = w*h/2
f = 0
if w%2 == 0 and h%2 == 0 and w//2 == x and h//2 == y:
    f = 1
print(s,f)
