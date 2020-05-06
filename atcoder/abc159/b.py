def is_pal(s):
    return s == s[::-1]


s = input()
n = len(s)
print('Yes' if is_pal(s) and is_pal(
    s[:n//2]) and is_pal(s[(n+1)//2:]) else 'No')
