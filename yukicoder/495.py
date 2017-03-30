s = input()
a,b = 0,0

for i in range(0,len(s)-1,5):
    if s[i:i+5] == '(^^*)':
        a += 1
    else:
        b += 1

print(a,b)
