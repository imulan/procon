def f(s):
    if s[0] == 'B':
        return -int(s[1])+1
    else:
        return int(s[0])


s, t = input().split()
print(abs(f(s)-f(t)))
