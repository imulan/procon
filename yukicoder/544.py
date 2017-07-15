n = input()
a,b = '',''

for c in n:
    if c == '7':
        a += '1'
        b += '6'
    else:
        a += c
        b += '0'

print(int(a),int(b))
