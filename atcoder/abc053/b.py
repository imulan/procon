s = input()

a,z = 0, len(s)-1

while s[a] != 'A':
    a += 1
while s[z] != 'Z':
    z -= 1

print(z-a+1)
