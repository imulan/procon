s = input()
t = input()

a = 0
for i in range(3):
    if s[i] == t[i]:
        a += 1
print(a)
