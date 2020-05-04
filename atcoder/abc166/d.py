N = 200

x = int(input())
A, B = 0, 0
for a in range(N):
    for b in range(-N, N):
        if a**5 - b**5 == x:
            A, B = a, b

print(A, B)
