f = [0 for _ in range(10)]
for _ in range(10):
    s = input()
    for i in range(10):
        if s[i] == 'o':
            f[i] = 1
print('Yes' if sum(f) == 10 else 'No')
