a, b, n = map(int, input().split())


def f(x):
    return a*x//b - x//b*a


print(f(min(b-1, n)))
