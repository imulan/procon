def f(n):
    a = 0
    while n%5 == 0:
        n //= 5
        n *= 4
        a += 1

    while n%3 == 0:
        n //= 3
        n *= 2
        a += 1

    while n%2 == 0:
        n //= 2
        a += 1

    if n != 1:
        return -1
    return a

q = int(input())
for i in range(q):
    n = int(input())
    print(f(n))
