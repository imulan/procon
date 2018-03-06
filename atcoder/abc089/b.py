n = int(input())
color = set()
for c in input().split():
    color.add(c)

print('Three' if len(color) == 3 else 'Four')
