n = int(input())
screen = 2
for i in range(n):
    level = i+1
    t = (i+1)*(i+2)
    t2 = t**2

    print((t2-screen)//level)

    screen = t
