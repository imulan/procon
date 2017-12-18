n = int(input())

ct = 0
while n//2 != 0:
    n = n//2
    ct += 1

print(2**ct)
